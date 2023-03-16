#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 80

int main() {
	int nbCharRd, nbCharWr;

	int pipefd[2];
	int ret = pipe(pipefd);

	int childId = fork();

	// PAPA
	if (childId > 0) {
		ret = close(pipefd[0]);

		char bufRd[TAILLE];
		nbCharRd = read(0, bufRd, TAILLE);

		while (nbCharRd > 0) {
			nbCharWr = write(pipefd[1], bufRd, nbCharRd);
			nbCharRd = read(0, bufRd, TAILLE);
		}

		ret = close(pipefd[1]);

	// PA PAPA
	} else {
		ret = close(pipefd[1]);

		char bufPipeRd[TAILLE];
		nbCharRd = read(pipefd[0], bufPipeRd, TAILLE);
		while (nbCharRd > 0) {

			bufPipeRd[nbCharRd - 1] = 0;
			for (int i = 0; i < strlen(bufPipeRd); i++) {
				bufPipeRd[i] = tolower(bufPipeRd[i]);
			}
			bufPipeRd[nbCharRd - 1] = '\n';
			
			nbCharWr = write(1, bufPipeRd, nbCharRd);
			nbCharRd = read(pipefd[0], bufPipeRd, TAILLE);
		}

		ret = close(pipefd[0]);
	}

	printf("\nje vous print sinon j'ai erreur unused:\nret: %d\nnbCharWr: %d\n", ret, nbCharWr);
}