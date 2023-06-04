#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "inscriptionRequest.h"
#include "utils_v2.h"

int main() {
	int fd[2];
	spipe(fd);

	int childId = sfork();

	int nbAccepteesPapa = 0;
	int nbAccepteesPaPapa = 0;

	if (childId != 0) {
		// PAPA

		InscriptionRequest inscription;
		int i = 1;

		int nbCharRd = sread(0, &inscription, sizeof(InscriptionRequest));
		while(nbCharRd > 0) {
			if (i % 2 == 0) {
				char trtPapa[1000]; 
				sprintf(trtPapa, "Trt par le père : %s %s %d\n", inscription.name, inscription.firstname, inscription.nbYearPastInEducation);
				swrite(1, trtPapa, strlen(trtPapa));

				nbAccepteesPapa++;
			} else {
				char trtPaPapa[1000]; 
				sprintf(trtPaPapa, "Trt par le fils : %s %s %d\n", inscription.name, inscription.firstname, inscription.nbYearPastInEducation);
				swrite(1, trtPaPapa, strlen(trtPaPapa));

				swrite(fd[1], &inscription, sizeof(InscriptionRequest));

				int res = 0;
				sread(fd[0], &res, sizeof(int));

				if (res == 1) {
					nbAccepteesPaPapa++;
				}
			}

			i++;
			nbCharRd = sread(0, &inscription, sizeof(InscriptionRequest));
		}

		
		sclose(fd[1]);
		sclose(fd[0]);
	} else {
		// PA PAPA

		InscriptionRequest inscription;

		int nbCharRd = sread(fd[0], &inscription, sizeof(InscriptionRequest));
		while (nbCharRd > 0) {
			int res = 0;
			if (inscription.nbYearPastInEducation < 3) {
				res = 1;
			}
			
			swrite(fd[1], &res, sizeof(int));

			nbCharRd = sread(fd[0], &inscription, sizeof(InscriptionRequest));
		}

		sclose(fd[1]);
		sclose(fd[0]);
	}

	char fin[1000];
	sprintf(fin, "Acceptés par papa: %d\nAcceptés par pa papa: %d\n", nbAccepteesPapa, nbAccepteesPaPapa);
	write(1, fin, strlen(fin));
}