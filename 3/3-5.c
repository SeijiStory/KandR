#include <stdio.h>
#include <stdlib.h>
#include "reverse.h"

#define SIZE 64

int itob(unsigned int x, unsigned char n, char *s);
char itoc(char x);
int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("usage: 3-5 [base < 62] ...\n");
		return 1;
	}
	int i;
	char str[32];
	unsigned char n = strtoul(argv[1], NULL, 10);
	if (n > 62 || n == 0) {
		printf("usage: 3-5 [1 < base < 62] ...\n");
		return 1;
	}
	for (i = 2; i < argc; ++i) {
		int x = strtol(argv[i], NULL, 10);
		itob(x, n, str);
		printf("%s ", str);
	}
	printf("\b\n");
	return 0;
}

int itob(unsigned int x, unsigned char n, char *s)
{
	if (!s)
		return 1;
	if (n > 62)
		return 2;
	unsigned char remainder = 1;
	size_t i = 0;
	do {
		remainder = x % n;
		s[i++] = itoc(remainder);
		x /= n;
	} while (x > 0);
	s[i] = '\0';
	reverse(s);
	return 0;
}

char itoc(char x)
{
	if (x <= 9)
		return x + '0';
	else if (x > 9 && x < 36)
		return x - 10 + 'A';
	else if (x >= 36 && x <= 62)
		return x - 36 + 'a';
	else
		return 0;
}
