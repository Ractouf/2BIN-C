#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
PRE: n >= 2
POST: *sz est égal à la taille physique du tableau renvoyé par cette fonction
RES: un tableau trié contenant tous les nombres premies strictement plus petits que n si aucune erreur n'est survenue et NULL si une erreur est survenue
*/

int* prime_numbres (int n, int* sz) {
	bool *erato = malloc(n * sizeof(bool));
  if (erato == NULL) {
    return NULL;
  }
  
  for (int i = 0; i < n; i++) {
  	erato[i] = true;
  }
  erato[0] = false;
  erato[1] = false;
  
  *sz = 0;
  for(int i = 2; i < n; i++) {
    if (erato[i]) {
      (*sz)++;
      for(int j = 2 * i; j < n; j += i) {
        erato[j] = false;
      }
    }
  }
  
  int *res = malloc(*sz * sizeof(int));
  if (res == NULL) {
    return NULL;
  }

  int j = 0;
  for(int i = 0; i < n; i++) {
    if (erato[i]) {
      res[j] = i;
      j++;
    }
  }  
  
  free(erato);
  return res;
}

int main() {
	int a;
	while (1) {
		printf("Veuillez entrer un entier : ");
		if (scanf("%d", &a) != 1) {
			while ((a = getchar()) != '\n' && a != EOF);
			continue;
		}
		break;
	}

	int sz = 0;

	int* tab = prime_numbres (a, &sz);

	for (int i = 0; i < sz; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
	free(tab);
}