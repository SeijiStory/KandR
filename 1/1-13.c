#include <stdio.h>

#define WIDTH 80

int main(int argc, char **argv)
{
	int c;
	int words[WIDTH];
	int count = 0;
	int max = 0;
	char space = 0;

	int i = 0;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ': case '\n': case '\t':
			if (!space) {
				words[i++] = count;
				max = count > max ? count : max;
				count = 0;
				space = 1;
			}
			break;
		default:
			space = 0;
			count++;
			break;
		}
	}

	size_t k = 0;
	int j = max;
	while (j > 0) {
		for (k = 0; k < i; ++k)
			j <= words[k] ? putchar('#') : putchar(' ');
		putchar('\n');
		j--;
	}

	return 0;
}
