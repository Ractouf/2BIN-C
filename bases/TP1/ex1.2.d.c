#include <stdlib.h>
#include <stdio.h>

int main() {
	char A;
	char a;
	for (A = 'A'; A <= 'Z'; ++A) {
		printf("Caractère = %c\tcode déc. = %d\tcode hexa. = %x\n",A,A,A);
	}

	for (a = '0'; a <= '9'; ++a)
	{
		printf("Caractère = %c\tcode déc. = %d\tcode hexa. = %x\n",a,a,a);
	}

	exit(0);
}