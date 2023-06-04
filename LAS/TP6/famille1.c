#include <sys/types.h>
#include <unistd.h>

#include "utils_v2.h"

#define SEM_KEY 369
#define PERM 0666

void childProcess() {
	int sem_id = sem_get(SEM_KEY, 1);

	sem_down0(sem_id);
	for (int i = 0; i < 3; i++) {
		sleep(1);
		printf("je suis le fils %d\n", getpid());
	}
	sem_up0(sem_id);
}


int main() {
	sem_create(SEM_KEY, 1, PERM, 1); // init semaphores before fork to avoid race conditions

	fork_and_run0(&childProcess);
	fork_and_run0(&childProcess);

	swait(NULL);
  	swait(NULL);
}