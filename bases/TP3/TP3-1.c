#include <stdio.h>
#include <stdlib.h>

int main() {
	int taille;

	while (1) {
		printf("Veuillez entrer le nombre de données : \n");
		if (scanf("%d", &taille) != 1) {
			while((taille = getchar()) != '\n' && taille != EOF);
			continue;
		}

		if (taille < 1) {
			continue;
		}
		break;
	}

	int* valeurs = (int*) malloc(taille * sizeof(int));
	if (valeurs == NULL) {
		printf("Out of memory");
		exit(0);
	}
	int nbValeursNeg = 0;
	int nbValeursPos = 0;


	for (int i = 0; i < taille; i++) {
		printf("Valeur nr%d : ", i + 1);
		int valeur;
		if (scanf("%d", &valeur) != 1) {
			while((valeur = getchar()) != '\n' && valeur != EOF);
			i--;
			continue;
		}

		if (valeur >= 0) {
			nbValeursPos ++;
		} else {
			nbValeursNeg ++;
		}

		valeurs[i] = valeur;
	}

	int* pos = (int*) malloc(nbValeursPos * sizeof(int));
	if (pos == NULL) {
		printf("Out of memory");
		exit(0);
	}
	int* neg = (int*) malloc(nbValeursNeg * sizeof(int));
	if (neg == NULL) {
		printf("Out of memory");
		exit(0);
	}

	int ipos = 0;
	int ineg = 0;

	for (int i = 0; i < taille; i++) {
		if (valeurs[i] >= 0) {
			pos[ipos] = valeurs[i];
			ipos ++;
		} else {
			neg[ineg] = valeurs[i];
			ineg ++;
		}
	}

	for (int i = 0; i < nbValeursPos; i++) {
		printf("%d ", pos[i]);
	}
	printf("\n");
	for (int i = 0; i < nbValeursNeg; i++) {
		printf("%d ", neg[i]);
	}
	printf("\n");

	free(valeurs);
	free(pos);
	free(neg);

	exit(1);
}