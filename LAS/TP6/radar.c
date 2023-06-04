#include <unistd.h>

#include "utils_v2.h"

#define KEY 369
#define PERM 0666

int main() {
	int shm_id = sshmget(KEY, sizeof(int), IPC_CREAT | PERM);

	int* radar = sshmat(shm_id);

	int i = 0;
	while (i != 20) {
		*radar = randomIntBetween(0, 100);
		printf("%d\n", *radar);
		sleep(3);
		i++;
	}

	sshmdt(radar);
}