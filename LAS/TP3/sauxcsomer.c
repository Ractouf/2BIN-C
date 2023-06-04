#include <string.h>
#include <ctype.h>

#include "utils_v2.h"

#define TAILLE 80

int main() {
	int nbCharRd;

	int pipefd[2];
	spipe(pipefd);

	int childId = sfork();

	// PAPA
	if (childId != 0) {
		sclose(pipefd[0]);

		char bufRd[TAILLE];

		nbCharRd = sread(0, bufRd, TAILLE);
		while (nbCharRd > 0) {
			swrite(pipefd[1], bufRd, nbCharRd);
			nbCharRd = sread(0, bufRd, TAILLE);
		}

		sclose(pipefd[1]);

	// PA PAPA
	} else {
		sclose(pipefd[1]);

		char bufPipeRd[TAILLE];
		nbCharRd = sread(pipefd[0], bufPipeRd, TAILLE);
		while (nbCharRd > 0) {

			bufPipeRd[nbCharRd - 1] = 0;
			for (int i = 0; i < strlen(bufPipeRd); i++) {
				bufPipeRd[i] = toupper(bufPipeRd[i]);
			}
			bufPipeRd[nbCharRd - 1] = '\n';
			
			swrite(1, bufPipeRd, nbCharRd);
			nbCharRd = sread(pipefd[0], bufPipeRd, TAILLE);
		}

		sclose(pipefd[0]);
	}
}