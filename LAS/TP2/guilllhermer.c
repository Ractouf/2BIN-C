#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	int childPid = fork();
	if (childPid == -1) {
		perror("ça a pas marché le fork");
		exit(1);
	}

	if (childPid != 0) {
		int status;
		int waitId = waitpid(childPid, &status, 0);
		printf("Child status : %d\n", status);
		printf("1 2 3\\n\n");
	} else {
		printf("**Enfant**\n");
		printf("4 5 6\\n\n");
		exit(1);
	}

	exit(0);
}
