#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main() {
	int notes[MAX] = {0};
	int note;

	int i = 0;
	int somme = 0;

	while (i < MAX && scanf("%d", &note) != EOF) {
		notes[i] = note;
		somme += note;
		i ++;
	}

	int moyenne = somme / i;
	printf("Moyenne de la classe = %d\n", moyenne);

	somme = 0;
	for (int j = 0; j < i; j++) {
		printf("Note nr%d(%d)\n", j + 1, notes[j]);
		int ecart = notes[j] - moyenne;
		printf("écart à la moyenne = %d\n", ecart);

		somme += ecart * ecart;
	}
	
	printf("Variance : %d\n", somme / i);

	exit(1);
}