#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t len = 0;
	char *line = NULL;

	while ((len = getline(&line, &n, stdin)) > -1)
		if (len > 80)
			printf("%s", line);
	putchar('\n');
	free(line);
	return 0;
}
