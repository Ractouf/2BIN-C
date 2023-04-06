#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLE 27

int main(int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		printf("Mot nr%d: %s\n", i, argv[i]);
	}

	char mot[TAILLE + 2];
	int recherchePasTrouvee = 0;
	int found = 0;

	while(fgets(mot, TAILLE + 2, stdin) != NULL) {
		int longueur = strlen(mot) - 1;

		if (longueur == TAILLE + 1 && mot[TAILLE - 1] != '\n') {
			printf("Mot trop long !\n");
			while(fgets(mot, TAILLE + 2, stdin) && mot[strlen(mot) - 1] != '\n');
			continue;
		}

		printf("Mot : %sLongueur : %d\n", mot, longueur);

		mot[longueur] = '\0';

		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], mot) == 0) {
				printf("présent\n");
				found = 1;
				break;
			}
		}
		if (found == 0) {
			printf("absent\n");
			recherchePasTrouvee ++;
		}
		found = 0;
	}

	printf("Nombre de recherches non trouvées : %d\n", recherchePasTrouvee);
	exit(1);
}