#include <stdlib.h>
#include <stdio.h>

int main() {
	int a, b, c;
	printf("Veuillez entrer deux entiers: \n");
	scanf("%d",&a);
	scanf("%d",&b);

	printf("Valeur initiale de a: \n");
	printf("%d \n",a);

	printf("Valeur initiale de b: \n");
	printf("%d \n",b);

	c = a;
	a = b;
	b = c;

	printf("Valeur après changement de a: \n");
	printf("%d \n",a);

	printf("Valeur après changement de b: \n");
	printf("%d \n",b);

	exit(0);
}