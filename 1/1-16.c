#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char **argv)
{
	size_t max = 0;
	size_t n = 0;
	ssize_t len = 0;
	char *line = NULL;
	char *longest = NULL;

	while ((len = getline(&line, &n, stdin)) != -1) {
		if (len > max) {
			max = len;
			longest = realloc(longest, len);
			strncpy(longest, line, len);
		}
	}
	if (max > 0) {
		printf("%s", longest);
		printf("\n%ld chars long\n", max);
	}
	free(line);
	free(longest);
	return 0;
}
