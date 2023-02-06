#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crypt.h"

static char square[8][8] ={
	{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'},
	{'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'},
	{'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X'},
	{'Y', 'Z', '0', '1', '2', '3', '4', '5'},
	{'6', '7', '8', '9', ' ', '!', '"', '#'},
	{'$', '%', '&', '\'', '(', ')', '*', '+'},
	{',', '-', '.', '/', ':', ';', '<', '='},
	{'>', '?', '@', '[', '\\', ']', '^', '_'}
};

static char* cryptCarrePolybe(char* msg) {
	int size = strlen(msg);

	char* tab = malloc(size* 2 * sizeof(char));
	if (tab == NULL) {
		perror("ça a pas marché");
		exit(1);
	}

	int sizetab = 0;
	
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j] == msg[k]) {
					tab[sizetab] = i;
					tab[sizetab + 1] = j;
					sizetab += 2;
					continue;
				}
			}
		}
	}
	return tab;
}

static char* decryptCarrePolybe(char* msg) {
	int size = strlen(msg);

	char* tab = malloc(size* 2 * sizeof(char));
	if (tab == NULL) {
		perror("ça a pas marché");
		exit(1);
	}

	int sizetab = 0;
	
	for (int k = 0; k < size; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (square[i][j] == msg[k]) {
					tab[sizetab] = i;
					tab[sizetab + 1] = j;
					sizetab += 2;
					continue;
				}
			}
		}
	}
	return tab;
}
