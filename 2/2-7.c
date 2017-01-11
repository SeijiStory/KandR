#include <stdio.h>
#include <stdlib.h>
#include "printbin.h"

unsigned long long invert(unsigned long long x, size_t p, size_t n);
int main(int argc, char **argv)
{
	if (argc < 4)
		return 1;
	unsigned int x = invert(strtoll(argv[1], NULL, 10),
				strtoul(argv[2], NULL, 10),
				strtoul(argv[3], NULL, 10));
	printbin(x);
	printf("%u\n", x);
	return 0;
}

unsigned long long invert(unsigned long long x, size_t p, size_t n)
{
	unsigned long long mask = ~((unsigned long long)(~0) << n);
	if (p < n)
		mask >>= n - p - 1;
	else
		mask <<= p - n + 1;
	unsigned long long y = x & mask;
	x &= ~mask;
	y = ~y & mask;
	x |= y;
	return x;
}
