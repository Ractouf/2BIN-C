#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b;
	while(1) {
		printf("Veuillez entrer un entier : \n");
		if (scanf("%d", &a) != 1) {
			while((a = getchar()) != '\n' && a != EOF);
			continue;
		}
		
		printf("Veuillez entrer un autre entier : \n");
		if (scanf("%d", &b) != 1) {
			while((b = getchar()) != '\n' && b != EOF);
			continue;
		}

		if (a < 1 || a > 100 || b < 1 || b > 100) {
			continue;
		}
		break;
	}

	char** tab = (char**) malloc(a * sizeof(char*));
	if (tab == NULL) {
		printf("Out of memory");
		exit(1);
	}

	for (int i = 0; i < a; i++) {
		tab [i] = (char*) malloc(b * sizeof(char));
		if (tab[i] == NULL) {
			printf("Out of memory");
			exit(1);
		}
	}

	char c = 'A';
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			printf("%c en ligne %d et colonne %d\n", c, i, j);

			if (c == 'Z') {
				c = 'A';
			} else {
				c ++;
			}
		}
	}

	for (int i = 0; i < a; i++) {
		free(tab[i]);
	}
	free(tab);

	exit(1);
}