#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

static const char *const HELLO = "Hello. Je suis le sigusr1_handler\n";

volatile sig_atomic_t end = 0;

void sigusr1_handler (int sig) {
	const size_t sz = strlen(HELLO);
	write(1, HELLO, sz);

	char* signal = "Signal SIGUSR1 reçu !\n";
	write(1, signal, strlen(signal));

	end = 1;
}

void child_handler () {
	pid_t pid = getpid();
	pid_t ppid = getppid();
	printf("Je suis le processus %d, fils de %d\n", pid, ppid);

	while (end == 0) {
		sleep(1);
	}
}

int main () {
	struct sigaction action = {0};
	action.sa_handler = sigusr1_handler;

	int ret = sigaction(SIGUSR1, &action, NULL);
	checkNeg(ret, "erreur sigaction 1");

	pid_t childId = fork_and_run0(child_handler);

	pid_t pid = getpid();
	printf("Je suis le processus pere (PID %d) - ", pid);

	printf("envoi du signal SIGUSR1 à mon fils (PID %d)\n", childId);
	ret = kill(childId, SIGUSR1);
	checkNeg(ret, "erreur kill SIGUSR1");

	int statut;
	swaitpid(childId, &statut,0);
	printf("Mon fils %d s'est terminé avec le statut: %d\n", childId, WEXITSTATUS(statut));
}