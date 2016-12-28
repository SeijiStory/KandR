#include <stdio.h>
#include <stdlib.h>

/* reverse - reverse string
 * DESCRIPTION
 *	reverse() takes the data in str and reverses its order. The buffer is
 *	null-terminated, and a final newline will appear in its position in
 *	the original string if it exists.
 * RETURN VALUE
 *	On success, reverse() returns the address of the reversed string. On
 *	failure, reverse() returns NULL.
 */
char *reverse(char *str);
int main(int argc, char **argv)
{
	size_t n;
	char *line = NULL;
	while (getline(&line, &n, stdin) > -1) {
		reverse(line);
		printf("%s", line);
	}
	free(line);
	return 0;
}

char *reverse(char *str)
{
	if (!str)
		return NULL;
	size_t i;
	size_t n;
	for (n = 0; str[n] != '\0'; ++n);
	n--;
	if (n < 2)
		return NULL;
	if (str[n] == '\n') n--;
	for (i = 0; i < n; ++i, --n) {
		if (str[n] == str[i])
			continue;
		str[n] ^= str[i];
		str[i] ^= str[n];
		str[n] ^= str[i];
	}
	return str;
}
