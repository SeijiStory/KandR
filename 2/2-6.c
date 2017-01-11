#include <stdio.h>
#include <stdlib.h>
#include "printbin.h"

unsigned long long setbits(unsigned long long x,
			   size_t p, size_t n,
			   unsigned long long y);
int main(int argc, char **argv)
{
	if (argc < 5)
		return 1;
	unsigned int x = setbits(strtoll(argv[1], NULL, 10),
				 strtoul(argv[2], NULL, 10),
				 strtoul(argv[3], NULL, 10),
				 strtoll(argv[4], NULL, 10));
	printbin(x);
	printf("%u\n", x);
	return 0;
}

unsigned long long setbits(unsigned long long x,
			   size_t p, size_t n,
			   unsigned long long y)
{
	unsigned long long mask = ~((unsigned long long)(~0) << n);
	y &= mask;
	if (p < n)
		y >>= n - p - 1;
	else
		y <<= p - n + 1;
	x |= y;
	return x;
}
