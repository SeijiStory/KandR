#include <stdio.h>
#include "reverse.h"

#define SIZE 64
#define SMALLEST ((unsigned)(~0) ^ ((unsigned)(~0) >> 1))

void itoa(int n, char s[], size_t padding);
int main(int argc, char **argv)
{
	char str[SIZE];
	signed i = SMALLEST;
	size_t j;
	for (j = 0; j < 30; ++j) {
		itoa(i, str, j);
		printf("%s\n", str);
	}
	return 0;
}

void itoa(int n, char *s, size_t padding)
{
	size_t i = 0;
	int sign;
	char toobig;
	if (n == (signed)SMALLEST) {
		n = n + 1;
		toobig = 1;
	}
	if ((sign = n) < 0) 
		n = -n;
	do {
		s[i++] = n % 10 + '0'; 
		if (toobig) { 
			s[i-1] = (n % 10 == 9 ? '0' : s[i-1] + 1);
			toobig = 0;
		}
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	while (i < padding && i < SIZE)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
}
