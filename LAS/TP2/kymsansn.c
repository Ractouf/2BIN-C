#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int nbCharWr;
	int len;

	printf("Trois...deux...un...");

	int childPid = fork();
	if (childPid == -1) {
		perror("ça a pas marché le fork");
		exit(1);
	}

	if (childPid != 0) {
		//int status;
		//int waitId = waitpid(childPid, &status, 0);
	} else {
		printf("**Enfant**");
		printf("Partez !!");
	}

	exit(0);
}
