#include <stdio.h>

#define WIDTH 256

int putesc(char c);
int main(int argc, char **argv)
{
	int c;
	size_t chars[WIDTH];

	size_t i = 0;
	for (i = 0; i < WIDTH; ++i)
		chars[i] = 0;

	while ((c = getchar()) != EOF) {
		chars[c]++;
	}

	for (i = 0; i < WIDTH; ++i) {
		if (chars[i] > 0) {
			size_t j;
			putesc(i);
			printf(": ");
			for (j = 0; j < chars[i]; ++j)
				putchar('#');
			putchar('\n');
		}
	}

	return 0;
}

int putesc(char c)
{
	switch (c) {
	case ' ':
		printf("\\ ");
		break;
	case '\a':
		printf("\\a");
		break;
	case '\b':
		printf("\\b");
		break;
	case '\f':
		printf("\\f");
		break;
	case '\n':
		printf("\\n");
		break;
	case '\r':
		printf("\\r");
		break;
	case '\t':
		printf("\\t");
		break;
	case '\v':
		printf("\\v");
		break;
	case '\\':
		printf("\\\\");
		break;
	case '\'':
		printf("\\\'");
		break;
	case '\"':
		printf("\\\"");
		break;
	case '\?':
		printf("\\\?");
		break;
	default:
		printf(" %c", c);
		break;
	}
	return 0;
}
