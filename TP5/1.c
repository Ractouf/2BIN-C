#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
	
	char** tableauChar = malloc((argc - 1) * sizeof(char*));
	if (tableauChar == NULL) {
		exit(1);
	}

	for (int i = 1; i < argc; i++) {
		tableauChar[i] = malloc(strlen(argv[i]) * sizeof(char));	
	}

	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
			tableauChar[i][j] = toupper(argv[i][j]);
			printf("%c", tableauChar[i][j]);
		}
		printf(" ");
	}

	printf("\n");

	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
			printf("%c", argv[i][j]);
		}
		printf(" ");
	}

	printf("\n");

	for (int i = 0; i < argc; i++) {
		free(tableauChar[i]);
	}

	free(tableauChar);
}