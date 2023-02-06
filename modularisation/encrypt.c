#include <stdio.h>
#include <stdlib.h>

#include "utils_v1.h"
#include "crypt.h"

int main() {
	char* tab = readLine();

	printf("%s\n", encrypt(tab));

	exit(0);
}