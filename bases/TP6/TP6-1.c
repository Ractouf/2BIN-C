#include <stdio.h>
#include <stdlib.h>

/*
RES: max entre x et y
*/
int max (int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

int main() {
	int x, y;

	while (1) {
		printf("Veuillez entrer un entier : ");
		if (scanf("%d", &x) != 1) {
			while ((x = getchar()) != '\n' && x != EOF);
			continue;
		}

		printf("Veuillez entrer un entier : ");
		if (scanf("%d", &y) != 1) {
			while ((y = getchar()) != '\n' && y != EOF);
			continue;
		}
		break;
	}
	
	printf("%d\n", max (x, y));
	exit(0);
}