#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "utils_v2.h"

#define TAILLE 10

int main (int argc, char **argv) {
	checkCond(argc != 3, "Incorrect amount of arguments\n");
	
	char bufRd[TAILLE + 1]; 

	/* Opening the file in write mode */
	int fd1 = sopen(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	int fd2 = sopen(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);

	
	char* msg = "Enter text lines (Ctrl-D to terminate):\n";
	int len = strlen(msg);
	swrite(1, msg, len);

	/* Reading STDIN, then writing file, up to EOF (Ctrl-D) */
	int nbCharRd;

	while ((nbCharRd = sread(0, bufRd, TAILLE + 1))) {

		if (bufRd[nbCharRd - 1] == '\n') {
			bufRd[nbCharRd] = '\0';

			if (isupper(bufRd[0])) {
		        swrite(fd2, bufRd, nbCharRd);
		    } else {
		        swrite(fd1, bufRd, nbCharRd);
		    }
		} else {
			char c;

			while ((sread(0, &c, 1)) && (c != '\n'));
		}
	}

  /* Closing fd */
  sclose(fd1);
  sclose(fd2);
}
