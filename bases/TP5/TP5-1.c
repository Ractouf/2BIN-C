#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {

	char** ligne = (char**) malloc((argc - 1) * sizeof(char*));

	for (int i = 0; i < argc - 1; ++i) {
		ligne[i] = (char*) malloc(strlen(argv[i + 1]) * sizeof(char));
	}

	for (int i = 0; i < argc - 1; i++) {
		for (int j = 0; j < strlen(argv[i + 1]); j++) {
			ligne[i][j] = toupper(argv[i + 1][j]);
		}
		printf("%s ", ligne[i]);
	}

	printf("\n");

	for (int i = 1; i < argc; i++) {
		printf("%s ", argv[i]);
	}

	printf("\n");

	for (int i = 0; i < argc - 1; i++) {
		free(ligne[i]);
	}

	free(ligne);

	exit(1);
}