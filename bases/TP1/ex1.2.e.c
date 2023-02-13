#include <stdlib.h>
#include <stdio.h>

int main() {
	int a;
	printf("Veuillez entrer un entier stirctement positif: \n");

	scanf("%d",&a);

	if (a < 1) {
		printf("L'entier n'est pas strictement positif\n");
		exit(2);
	}

	int b;

	for (b = 1; b <= a; ++b) {
		if (a % b == 0) {
			printf("%d divise %d\n",b,a);
		}
	}

	exit(0);
}