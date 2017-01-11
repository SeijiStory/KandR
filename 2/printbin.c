#include <stdio.h>
#include <limits.h>

/* Very poor and lazy way to print binary of x */
int printbin(unsigned long long x)
{
	char str[CHAR_BIT * sizeof(x)];
	ssize_t i = 0;
	while (x > 0) {
		str[i++] = x & 1;
		x >>= 1;
	}
	for (i = i - 1; i >= 0; --i)
		putchar(str[i] + '0');
	putchar('\n');
	return 0;
}
