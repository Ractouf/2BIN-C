#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char** coffres = (char**) malloc(200 * sizeof(char*));

	for (int i = 0; i < 200; i++) {
		coffres[i] = (char*) malloc(254 * sizeof(char));
	}

	char entree[254 + 2];
	int nbCoffres = 0;
	int found = 0;

	while (fgets(entree, 254 + 2, stdin) != NULL) {

		int longueur = strlen(entree) - 1;
		entree[longueur] = '\0';

		for (int i = 0; i < 200; i++) {
			if (strncmp(coffres[i], entree, 5) == 0) {
				found = 1;
				char* items = entree + 5;
				strcat(coffres[i], items);
				break;
			}
		}

		if (found == 0) {
			strcat(coffres[nbCoffres], entree);
			nbCoffres ++;
		}
		found = 0;

		printf("Coffres :\n");
		for (int i = 0; i < nbCoffres; i++) {
			printf("%s\n", coffres[i]);
		}
	}
	printf("sortie du programme");
	exit(1);
}