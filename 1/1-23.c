#include <stdio.h>
#include <string.h>

char *decomment(char *str);
int main(int argc, char **argv)
{
	size_t n = 0;
	char *line = NULL;
	char *nexthalf = NULL;
	char incomment = 0;

	while (getline(&line, &n, stdin) > -1) {
		size_t i;
		for (i = 0; line[i] != '\n' && line[i] != '\0'; ++i) {
			if (line[i] == '/');
		}
	}
}
