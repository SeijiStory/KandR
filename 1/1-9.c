#include <stdio.h>

int main(int argc, char **argv)
{
	char space = 0;
	int c;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			if (!space) {
				putchar(' ');
				space = 1;
			}
			break;
		default:
			space = 0;
			putchar(c);
			break;
		}
	}
	return 0;
}
