#include <stdio.h>

#define TABSTOP 8

int main(int argc, char **argv)
{
	size_t i = 1;
	int c;

	/*
	for (i = 0; i < 10; ++i)
		printf("|---l---");
	putchar('\n');
	i = 1;
	*/

	while ((c = getchar()) > EOF) {
		unsigned char j;
		switch (c) {
		case '\t':
			for (j = i; j <= TABSTOP; ++j)
				putchar(' ');
			i = 1;
			break;
		case '\n':
			putchar(c);
			i = 1;
			break;
		default:
			putchar(c);
			i = (i % TABSTOP) + 1;
			break;
		}
	}
	return 0;
}

// A wee		little test     line m8
