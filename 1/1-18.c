#include <stdio.h>

int main(int argc, char **argv)
{
	int c;
	char newline = 0;
	char space = 0;
	while ((c = getchar()) > -1) {
		switch (c) {
		case '\n':
			if (newline) {
				continue;
			} else {
				newline = 1;
				space = 0;
				putchar(c);
			}
			break;
		case ' ':
			if (space)
				continue;
			else
				space = 1;
			break;
		default:
			if (space) {
				putchar(' ');
				space = 0;
			}
			putchar(c);
		}
	}
}
