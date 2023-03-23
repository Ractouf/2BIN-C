#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

#define HEARTS 7

volatile sig_atomic_t end = 0;
volatile sig_atomic_t cpt = 1;

void sigchldhandler() {
  end = 1;
}

void sigusr1_handler (int sig) {
	char* signal = "Signal SIGUSR1 reçu !\n";
	write(1, signal, strlen(signal));
	
	cpt ++;
}

void child_handler () {
	pid_t pid = getpid();
	pid_t ppid = getppid();
	printf("Je suis le processus %d, fils de %d\n", pid, ppid);

	while (cpt <= HEARTS) {
		sleep(1);
	}
}

int main () {
	struct sigaction action = {0};
	action.sa_handler = sigusr1_handler;

	int ret = sigaction(SIGUSR1, &action, NULL);
	checkNeg(ret, "erreur sigaction 1");

	action.sa_handler = sigchldhandler;
	ret = sigaction(SIGCHLD, &action, NULL);
	checkNeg(ret, "erreur sigaction");

	pid_t childId = fork_and_run0(child_handler);

	pid_t pid = getpid();
	printf("Je suis le processus pere (PID %d)\n", pid);

	while (!end) {
		ret = kill(childId, SIGUSR1);
		checkNeg(ret, "erreur kill SIGUSR1");
		sleep(1);
	}

	printf("fin du père\n");
}
