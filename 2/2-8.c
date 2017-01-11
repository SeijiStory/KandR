#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "printbin.h"

#ifndef __GNUC__
#define __typeof__ typeof
#endif

/* Generic macro for rightrotate; may not work on all compilers */
#ifdef __GNUC__
#define rightrot(x, n)								\
	do {									\
		__typeof__(x) carry;						\
		size_t n1 = n;							\
		for (n1 = n1; n1 > 0; --n1) {					\
			carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);	\
			x >>= 1;						\
			x += carry;						\
		}								\
	} while (0)
#endif

unsigned char rightrotc(unsigned char x, size_t n);
unsigned short rightrots(unsigned short x, size_t n);
unsigned int rightrotd(unsigned int x, size_t n);
unsigned long rightrotl(unsigned long x, size_t n);
unsigned long long rightrotll(unsigned long long x, size_t n);

int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;
	printf("Function:\n");
	unsigned int x = rightrotd(strtoul(argv[1], NULL, 10),
				   strtoul(argv[2], NULL, 10));
	printbin(x);
	printf("%u\n", x);
	printf("Macro?:\n");
	unsigned long long x1 = strtoull(argv[1], NULL, 10);
	#ifdef rightrot
	rightrot(x1, strtoul(argv[2], NULL, 10));
	#else
	rightrotll(x1, strtoul(argv[2], NULL, 10));
	#endif
	printbin(x1);
	printf("%llu\n", x1);
	return 0;
}

unsigned char rightrotc(unsigned char x, size_t n)
{
	unsigned char carry;
	for (n = n; n > 0; --n) {
		carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);
		x >>= 1;
		x += carry;
	}
	return x;
}

unsigned short rightrots(unsigned short x, size_t n)
{
	unsigned short carry;
	for (n = n; n > 0; --n) {
		carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);
		x >>= 1;
		x += carry;
	}
	return x;
}

unsigned int rightrotd(unsigned int x, size_t n)
{
	unsigned int carry;
	for (n = n; n > 0; --n) {
		carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);
		x >>= 1;
		x += carry;
	}
	return x;
}

unsigned long rightrotl(unsigned long x, size_t n)
{
	unsigned long carry;
	for (n = n; n > 0; --n) {
		carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);
		x >>= 1;
		x += carry;
	}
	return x;
}

unsigned long long rightrotll(unsigned long long x, size_t n)
{
	unsigned long long carry;
	for (n = n; n > 0; --n) {
		carry = (x & 1) << ((sizeof(x) * CHAR_BIT) - 1);
		x >>= 1;
		x += carry;
	}
	return x;
}
