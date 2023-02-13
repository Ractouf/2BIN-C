#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv) {
	int** tableau;
	int n, m;

	printf("Entrez les dimentions de l'image\n");
	scanf("(%d,%d)", &n, &m);

	tableau = (int**)malloc(n*sizeof(int*));
	if (tableau == NULL) {
		perror("Problem");
		exit(2);
	}

	for (int i = 0; i < n; i++) {
		tableau[i] = (int*)malloc(m*sizeof(int));
		if (tableau[i] == NULL) {
			perror("Problem");
			exit(2);
		}
	}

	int profondeurBits = 0;
	int maxPossible = 0;
	printf("Profondeur d'image souhaitée\n");
	scanf("%d", &profondeurBits);
	maxPossible = pow(2, profondeurBits);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tableau[i][j] = rand() % maxPossible;
			printf("%d\t", tableau[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		free(tableau[i]);
	}

	free(tableau);
}