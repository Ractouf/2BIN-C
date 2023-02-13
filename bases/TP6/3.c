#include <stdio.h>
#include <stdlib.h>

int* prime_numbers (int entier, int* sz) {  
	int size = 0;

	for (int i = entier; i > 1; i--) {
		for (int j = 2; j < i; j++) {
		    if (i % j == 0) {
		    	break;
		    }
		    if (j == i - 1) {
		    	size ++;
		    }
	  	}	
	}

	int* tableau = malloc(size * sizeof(int));
	if (tableau == NULL) {
		return NULL;
	}

	int k = 0;

	for (int i = entier; i > 1; i--) {
		for (int j = 2; j < i; j++) {
		    if (i % j == 0) {
		    	break;
		    }
		    if (j == i - 1) {
		    	tableau[k] = i;
		    	k ++;
		    }
	  	}	
	}

	*sz = size;
	return tableau;
}

int main (int argc, char *argv[]) {
	
	int entier = 0;

	do {
		printf("Entrez un entier : ");
		if(!scanf("%d", &entier)) {
			printf("Des entiers silteplé\n");
			break;
		}
		if (entier < 2) {
			printf("Entier doit être >= 2");
		}
	} while (entier < 2);
	
	int szr;
	int* tableau = prime_numbers(entier, &szr);

	for (int i = 0; i < szr; i ++) {
		printf("%d\n", tableau[i]);
	}
}
