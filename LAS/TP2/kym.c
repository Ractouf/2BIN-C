#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

	int nbCharWr;
	int len;

	printf("Trois\n...\ndeux\n...\nun\n...\n");

	int childPid = fork();
	if (childPid == -1) {
		perror("ça a pas marché le fork\n");
		exit(1);
	}

	if (childPid != 0) {
		int status;
		int waitId = waitpid(childPid, &status, 0);
	} else {
		printf("\n**Enfant**\n\n");
		printf("Partez !!\n");
	}

	exit(0);
}
