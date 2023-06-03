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
	int fd1 = sopen(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	int fd2 = sopen(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);

	
	char* msg = "Enter text lines (Ctrl-D to terminate):\n";
	int len = strlen(msg);
	swrite(1, msg, len);

	/* Reading STDIN, then writing file, up to EOF (Ctrl-D) */
	int nbCharRd = sread(0, bufRd, TAILLE);

	while (nbCharRd > 0) {
	    if (isupper(bufRd[0])) {
	        swrite(fd2, bufRd, nbCharRd);
	    } else {
	        swrite(fd1, bufRd, nbCharRd);
	    }

		nbCharRd = sread(0, bufRd, TAILLE);
	}

  /* Closing fd */
  sclose(fd1);
  sclose(fd2);
}
