#include "utils_v2.h"

int main() {
	int a = 5;

	int childPid = sfork();

	if (childPid != 0) {
		// PAPA
		int status;
		swaitpid(childPid, &status, 0);
		int b = a * 5;
		printf("contenu de a: %d\ncontenu de b: %d\n", a, b);
	} else {
		// PA PAPA
		printf("Child PID : %d\n", childPid);
		int b = a * 2;
		printf("contenu de a: %d\ncontenu de b: %d\n", a, b);
	}
}
