#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int squeeze(char *dest, char *src);
int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;
	char *str = malloc(strlen(argv[1]+1));
	strcpy(str, argv[1]);
	squeeze(str, argv[2]);
	printf("%s\n", str);
	free(str);
	return 0;
}

int squeeze(char *dest, char *src)
{
	int i;
	int j;
	for (src; *src > '\0'; ++src) {
		j = 0;
		for (i = 0; dest[i] > '\0'; ++i)
			if (dest[i] != *src)
				dest[j++] = dest[i];
		dest[j] = '\0';
	}
	return 0;
}
