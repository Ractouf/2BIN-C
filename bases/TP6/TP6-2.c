#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
PRE: t: tableau de longueur sz
RES: true si le t contient un élément x, false sinon
*/
bool search(int* t, int sz, int x) {
	for (int i = 0; i < sz; i++){
		if (t[i] == x) {
			return true;
		}
	}
	return false;
}

int main() {
	int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int a;

	while (true) {
		printf("Veuillez entrer un entier : ");
		if (scanf("%d", &a) != 1) {
			while ((a = getchar()) != '\n' && a != EOF);
			continue;
		}

		break;
	}

	printf("Recherche de l'entier dans un tableau\n");
	printf("Entier trouvé : %s\n", search(tab, 10, a) ? "true" : "false");

	exit(0);
}