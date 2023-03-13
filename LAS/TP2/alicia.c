#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 20

int main() {
	int nbCharWr;
	char* str;
	int status;

	str = "Nom du fichier .sh à créer:\n";
	nbCharWr = write(1, str, strlen(str));

	char filename[TAILLE];
	int nbCharRd = read(0, filename, TAILLE);

	filename[nbCharRd - 1] = 0;

	int fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0700);

	char* shebang = "#!/bin/bash\n";
	write(fd, shebang, strlen(shebang));

	int childPid = fork();

	if (childPid == 0) {
		str = "\nls -l:\n";
		nbCharWr = write(1, str, strlen(str));

		execl("/bin/ls", "ls", "-l", filename, NULL);
	}

	int waitId = waitpid(childPid, &status, 0);

	str = "\nScript:\n";
	nbCharWr = write(1, str, strlen(str));

	char bufRd[TAILLE];
	nbCharRd = read(0, bufRd, TAILLE);

	while (nbCharRd > 0) {

		nbCharWr = write(fd, bufRd, nbCharRd);

		nbCharRd = read(0, bufRd, TAILLE);
	}

	childPid = fork();

	if (childPid == 0) {
		str = "\ncat:\n";
		nbCharWr = write(1, str, strlen(str));

		execl("/bin/cat", "cat", filename, NULL);
	}

	int waitId2 = waitpid(childPid, &status, 0);
	printf("%d", nbCharWr);

	exit(1);
}