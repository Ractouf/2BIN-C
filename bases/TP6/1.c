#include <stdio.h>
#include <stdlib.h>
/**
 * RES : le maximum entre a et b
 * si égal retourne -1
 * */
int max (int a, int b) {
	if (a == b) 
		return -1;
	
	if (a > b) 
		return a;
	
	return b;
}

int main (int argc, char *argv[]) {
	printf("Veuillez entrer 2 valeurs\n");

	int a;
    scanf("%d", &a);

    int b;
    scanf("%d", &b);

    int* t[2] = {2, 4};

    int result = max(a, b);

    if (result == -1)
    	printf("A = B\n");
    else
    	printf("Le max est : %d\n", result);
}
