#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 27
int main (int argc, char *argv[]) {

	for (int i = 0; i < argc - 1; i++) {
		printf("%d : %s\n", i + 1, argv[i + 1]);	
	}

	printf("\nentrez un mot:\n");

	char ligne[TAILLE + 2];
	int nombreTrouve = 0;

    while (fgets(ligne, TAILLE + 2, stdin) != NULL) {
    	int longueur = strlen(ligne) - 1;

    	if (longueur == 27 && ligne[27] != '\n') {
    		printf("erreur mot trop long\n");
    		while(fgets(ligne, TAILLE + 2, stdin) && ligne[strlen(ligne) - 1] != '\n');
    		continue;
    	}

        printf("mot: %slongueur: %d\n", ligne, longueur);
        
        ligne[longueur] = '\0';

        int present = 0;

        for (int i = 0; i < argc - 1; i++) {
        	if (strcmp(ligne, argv[i + 1]) == 0) {
        		present = 1;
        	}
		}

		if (present == 1) {
			printf("présent\n\n");
			nombreTrouve ++;
		} else {
			printf("absent\n\n");
		}
    }

    printf("nombre de mots trouvés : %d\n", nombreTrouve);
}