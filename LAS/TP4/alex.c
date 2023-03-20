#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *const HELLO = "Hello. Je suis le sigusr1_handler\n";

volatile sig_atomic_t end = 0;

void sigusr1_handler (int sig) {
	const size_t sz = strlen(HELLO);
	write(1, HELLO, sz);

	end = 1;
}

int main() {
	struct sigaction action = {0};
	action.sa_handler = sigusr1_handler;
	int ret = sigaction(SIGUSR1, &action, NULL);

	int childId = fork();

	if (childId > 0) {
		pid_t pid = getpid();
		printf("Je suis le processus pere (PID %d) - ", pid);
		ret = kill(childId, SIGUSR1);

		int statut;
		waitpid(childId, &statut,0);
		printf("Mon fils %d s'est terminé avec le statut: %d\n", childId, WEXITSTATUS(statut));
	} else {
		while (end == 0) {
			sleep(1);
		}
	}
}
