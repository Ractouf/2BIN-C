#include <stdio.h>
#include <stdlib.h>

#include "utils_v1.h"
#include "cryptPolybe.h"

int main() {
	char* tab = readLine();

	printf("%s\n", decrypt(tab));

	free(tab);

	exit(0);
}