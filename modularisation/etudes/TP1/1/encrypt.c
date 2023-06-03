#include "crypt.h"
#include "utils_v1.h"

int main() {
	char* line = readLine();

	printf("The line is : %s\n", line);

	line = encrypt(line);

	printf("The crypted line is : %s\n", line);

	exit(0);
}