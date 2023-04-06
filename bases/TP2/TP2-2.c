#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 100

int main() {
	int a;
	while(1) {
		printf("Veuillez entrer un entier entre 2 et 100\n");

		if (scanf("%d", &a) != 1) {
			while ((a = getchar()) != '\n' && a != EOF);
			continue;
		}

		if (a < 2 || a > LIMIT) {
			continue;
		}

		break;
	}
	printf("Nombres premiers inférieurs a 10 : \n");
	int tab[LIMIT] = {0};

	for (int i = 2; i <= sqrt(a); i++) {
		if (tab[i] == 0) {
			for (int j = i + i; j <= a; j += i) {
				tab[j] = 1;
			}
		}
	}

	for (int i = 2; i < a; i++) {
		if (tab[i] == 0) {
			printf("%d\n", i);
		}
	}

	exit(1);
}