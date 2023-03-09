#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {

	int nbCharWr;
	int len;

	char* msgCompteur = "Trois\n...\ndeux\n...\nun\n...\n";
	len = strlen(msgCompteur);
	nbCharWr = write(1, msgCompteur, len);
	if (len != nbCharWr) {
		perror("Le write il a pas marché");
		exit(1);
	}

	int childPid = fork();
	if (childPid == -1) {
		perror("ça a pas marché le fork\n");
		exit(1);
	}

	if (childPid != 0) {
		int status;
		int waitId = waitpid(childPid, &status, 0);	
	} else {
		char* msgEnfant = "\n**Enfant**\n\n";
		len = strlen(msgEnfant);
		nbCharWr = write(1, msgEnfant, len);
		if (len != nbCharWr) {
			perror("Le write il a pas marché");
			exit(1);
		}
		
		char* msgPartez = "Partez !!\n";
		len = strlen(msgPartez);
		nbCharWr = write(1, msgPartez, len);
		if (len != nbCharWr) {
			perror("Le write il a pas marché");
			exit(1);
		}
	}

	exit(0);
}
