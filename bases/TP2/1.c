#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main() {
	double notes[MAX] = {0};
	int i = 0;
	double somme = 0;
	
	while (scanf("%lf", &notes[i]) != EOF && i < MAX) {
		somme += notes[i];
		i++;
	}

	int j = i;
	double moyenne = somme / j;

	double ecarts[j] = {0}; 
	double sommeEcarts = 0;

	for (i = 0; i < j; i++) {
		ecarts[i] = notes[i] - moyenne;
		sommeEcarts += ecarts[i];
		printf("Ecart a la moyenne de %lf est %lf\n", notes[i], ecarts[i]);
	}

	printf("Moyenne : %lf\n", moyenne);
	printf("Moyenne des écarts : %lf\n", sommeEcarts / j);

	/*printf("Variance: %lf", );*/

	/*for (int j = 0; j < i; j++) {
		printf("%lf\t", notes[j]);
	}*/
	exit(0);
}