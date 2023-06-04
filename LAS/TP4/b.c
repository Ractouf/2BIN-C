
#include <unistd.h>
#include <string.h>

#include "utils_v2.h"

volatile sig_atomic_t end = 0;

void handler() {
	char* handler = "je suis handler\n";
	swrite(1, handler, strlen(handler));

	end = 1;
}

void child() {
	// armement du signal SIGUSR1
	ssigaction(SIGUSR1, handler);

	// déblocage du signal SIGUSR1
	sigset_t set;
	ssigemptyset (&set);
	sigaddset(&set, SIGUSR1);
	ssigprocmask(SIG_UNBLOCK, &set, NULL);

	printf("Je suis le fils\n");

	while (end == 0) {
		sleep(1);
	}
}

int main() {
	// blocage du signal SIGUSR1
	sigset_t set;
	ssigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	ssigprocmask(SIG_BLOCK, &set, NULL);

	int childId = fork_and_run0(child);

	printf("Je suis papa et je vais tuer mon enfant\n");
	skill(childId, SIGUSR1);

	int statut;
	swaitpid(childId, &statut,0);

	printf("Mon fils %d s'est terminé avec le statut: %d\n", childId, statut);
}
