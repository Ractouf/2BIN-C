#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils_v2.h"

#define TAILLE 80

int main (int argc, char **argv) {
	checkCond(argc != 3, "Incorrect amount of arguments\n");
	
	char bufRd[TAILLE]; 

	/* Opening the file in write mode */
	int fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	
	checkNeg(fd1, "Error opening file\n");
	checkNeg(fd2, "Error opening file\n");

	/* Reading STDIN, then writing file, up to EOF (Ctrl-D) */
	char* msg = "Enter text lines (Ctrl-D to terminate):\n";
	int len = strlen(msg);
	int nbCharWr = write(1, msg, len);
	checkCond(nbCharWr != len,"Error writing on stdout\n");

	int nbCharRd = read(0, bufRd, TAILLE);

	while (nbCharRd > 0) {
		write(1, bufRd, nbCharRd);

		int nbCharWr = write(fd1, bufRd, nbCharRd);

		checkCond(nbCharWr != nbCharRd,"Error writing file\n");

		nbCharRd = read(0, bufRd, TAILLE);
	}

	checkNeg(nbCharRd,"Error reading stdin\n");

  /* Closing fd */
  int res1 = close(fd1);
  int res2 = close(fd2);
  checkNeg(res1,"Error closing fd\n");
  checkNeg(res2,"Error closing fd\n");
}
