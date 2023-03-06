#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 80

int main (int argc, char **argv) {
	char bufRd[BUFFERSIZE]; 

	/* Opening the file in write mode */
	int fd1 = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	int fd2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	checkNeg(fd1, "Error opening file");
	checkNeg(fd2, "Error opening file");

	/* Reading STDIN, then writing file, up to EOF (Ctrl-D) */
	char* msg = "Enter text lines (Ctrl-D to terminate):\n";
	int len = strlen(msg);
	int nbCharWr = write(1, msg, len);
	checkCond(nbCharWr != len,"Error writing on stdout");

	int nbCharRd = read(0, bufRd, BUFFERSIZE);

	while (nbCharRd > 0) {
		// For the first use of the "write" function, 
		// we assume that it is able to write "BUFFERSIZE" bytes at once. 
		// Be careful, this assumption is too strong. 
		// We are going to fix this later in the course.
		nbCharWr = write(fd, bufRd, nbCharRd);
		checkCond(nbCharWr != nbCharRd,"Error writing file");
		nbCharRd = read(0, bufRd, BUFFERSIZE);
	}

	checkNeg(nbCharRd,"Error reading stdin");

	/* Closing fd */
	int res = close(fd);
	checkNeg(res,"Error closing fd");
}
