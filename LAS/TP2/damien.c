#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int a = 5;
	int b = 0;

	int childPid = fork();
	if (childPid == -1) {
		perror("ça a pas marché le fork\n");
		exit(1);
	}

	if (childPid != 0) {
		printf("Child PID : %d\n", childPid);
		int status;
		int waitId = waitpid(childPid, &status, 0);
		b = a * 5;
		printf("contenu de a: %d\ncontenu de b: %d\n", a, b);
	} else {
		printf("Child PID : %d\n", childPid);
		b = a * 2;
		printf("contenu de a: %d\ncontenu de b: %d\n", a, b);
	}
}
