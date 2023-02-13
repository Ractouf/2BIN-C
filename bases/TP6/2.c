#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * PRE : t : tableau de longueur sz
 * RES : true si le t contient un élément e, false sinon
*/
bool search (int* t, int sz, int e) {
	for (int i = 0; i < sz; i ++)
		if (t[i] == e)
			return true;

	return false;
}

int main (int argc, char *argv[]) {
	printf("Veuillez entrer la taille du tableau que vous souhaitez créer (c'est limité a 20 sinon c'est trop)\n");
	int sz = 0;
	scanf("%d", &sz);

	if (sz < 1 || sz > 20) {
		printf("t'abuses gro ...\n");
		exit(1);
	}

	int* t = malloc(sz * sizeof(int));

	for (int i = 0; i < sz; i ++) {
		printf("Valeur nr %d :\n", i + 1);

		if(!scanf("%d", &t[i])) {
			printf("Des entiers silteplé\n");
			exit(1);
		}
	}

	printf("Veuillez entrer une valeur a chercher\n");

	int a;
    scanf("%d", &a);

    if (search(t, sz, a))
    	printf("Présent\n");
    else
    	printf("Absent\n");
}
