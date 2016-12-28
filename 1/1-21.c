#include <stdio.h>

#define TABSTOP 8

int main(int argc, char **argv)
{
	size_t spaces = 0;
	int c;

	while ((c = getchar()) > EOF) {
		size_t i;
		switch (c) {
		case ' ':
			spaces++;
			if (spaces == TABSTOP) {
				putchar('\t');
				spaces = 0;
			}
			break;
		default:
			for (i = 0; i < spaces; ++i)
				putchar(' ');
			spaces = 0;
			putchar(c);
		}
	}
}
