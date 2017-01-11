#include <stdio.h>

#define SIZE 1024

int main (int argc, char **argv)
{
	unsigned int i;
	int c;
	char s[SIZE];
	/* & can be equivalent to && in this case */
	for (i = 0; (i < SIZE-1) &
		     ((c = getchar()) != '\n') &
		     (c > EOF); ++i)
		s[i] = c;
	printf("%.*s", SIZE, s);
	return 0;
}
