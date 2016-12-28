#include <stdio.h>

int main(int argc, char **argv)
{
	int c;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ': case '\n': case '\t':
			putchar('\n');
			break;
		default:
			putchar(c);
			break;
		}
	}
	return 0;
}
