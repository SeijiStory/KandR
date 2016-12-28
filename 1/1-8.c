#include <stdio.h>

int main(int argc, char **argv)
{
	size_t blanks = 0;
	size_t tabs = 0;
	size_t newlines = 0;
	int c;
	while ((c = getchar()) != EOF) {
		switch (c) {
		case ' ':
			blanks++;
			break;
		case '\t':
			tabs++;
			break;
		case '\n':
			newlines++;
			break;
		default:
			continue;
		}
	}
	printf("Blanks: %lu\nTabs: %lu\nNewlines: %lu\n",
	       blanks, tabs, newlines);
	return 0;
}
