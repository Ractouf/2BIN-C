#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "utils_v2.h"

void sigusr1_handler (int sig) {
	strsignal(sig);
}

void handler (int sig) {
	char* msg = " Signal '";
	write(1, msg, strlen(msg));
	msg = strsignal(sig);
	write(1, msg, strlen(msg));
	msg = "' reçu ";
	write(1, msg, strlen(msg));
}

int main () {
	struct sigaction action = {0};
	action.sa_handler = handler;
	for (int i = 0; i < 32; i++) {
		int res = sigaction(i, &action, NULL);
		if (res != 0) {
			printf("Signal %d (%s) non capture\n", i, strsignal(i));  
		}
	}

	printf("\n");

	while (1) {
		char* dot = ".";
		write(1, dot, strlen(dot));
		sleep(1);
	}

	printf("fin du programme\n");
}
