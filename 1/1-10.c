#include <stdio.h>

int main(int argc, char **argv)
{
	char space = 0;
	int c;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case '\\':
			printf("\\\\");
			break;
		case '\b':
			printf("\\b");
			break;
		case '\t':
			printf("\\t");
			break;
		default:
			putchar(c);
			break;
		}
	}
	return 0;
}
