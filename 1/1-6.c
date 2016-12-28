#include <stdio.h>

int main(int argc, char **argv)
{
	int c;
	while ((c = getchar()) != EOF)
		printf("%d ", c != EOF);
	printf("%d\n", c != EOF);
	return 0;
}
