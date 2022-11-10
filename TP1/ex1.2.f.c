#include <stdlib.h>
#include <stdio.h>

int main() {
	int a,b;
	printf("Veuillez entrer deux entier stirctement positifs: \n");

	scanf("%d",&a);
	scanf("%d",&b);

	if (a < 1 || b < 1) {
		printf("L'entier n'est pas strictement positif\n");
		exit(2);
	}

	if (b > a) {
		int c;
		c = a;
		a = b;
		b = c;
	}

	int i;
	int reste = 0;
	int div = 0;

	for (i = b; i < a + a; i += b) {
		++ div;
		if (i > a) {
			reste = i - a;
			break;
		}
		if (i == a) {
			break;
		}
	}
	printf("%d / %d = %d avec reste = %d\n",a,b,div,reste);
	

	exit(0);
}