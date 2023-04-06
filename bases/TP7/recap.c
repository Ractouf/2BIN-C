#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char** tab = (char**) malloc((argc - 1) * sizeof(char*));
	if (tab == NULL) {
		perror("Out of memory");
		exit(1);
	}

	int nbDoublons = 0;
	int found = 0;
	int k = 0;

	for (int i = 0; i < argc - 1; i++) {
		for (int j = 0; j < k; j++) {
			if (strcmp(argv[i + 1], tab[j]) == 0) {
			 	found = 1;
			 	break;
			} 
		}
		if (found == 0) {
			tab[k] = (char*) malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
			if (tab[k] == NULL) {
				perror("Out of memory");
				exit(1);
			}

			strcpy(tab[k], argv[i + 1]);
			k ++;
		}
		found = 0;
	}

	tab = (char**) realloc(tab, k * sizeof(char*));

	for (int i = 0; i < k; i++) {
		printf("%d - %s\n",i + 1, tab[i]);
	}

	int min;
	char* temp;
	for (int i = 0; i < k - 1; i++) {
		min = i;
		for (int j = i + 1; j < k; j++) {
			if (strcmp(tab[j], tab[min]) < 0) {
				min = j;
			}
		}
		if (min != i) {
			temp = tab[i];
			tab[i] = tab[min];
			tab[min] = temp;
		}
	}

	for (int i = 0; i < k; i++) {
		printf("%d - %s\n",i + 1, tab[i]);
	}

	for (int i = 1; i < k; i++) {
		free (tab[i - 1]);
	}
	free (tab);

	exit(0);
}