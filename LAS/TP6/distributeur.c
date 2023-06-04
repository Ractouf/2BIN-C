#include "utils_v2.h"

#define SHM_KEY 248
#define PERM 0666

int main() {
	int shm_id = sshmget(SHM_KEY, 2 * sizeof(int), IPC_CREAT | PERM);

	int* file = sshmat(shm_id);

	(*file)++;
	printf("%d\n", *file);

	sshmdt(file);
}
