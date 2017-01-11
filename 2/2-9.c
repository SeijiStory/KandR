#include <stdio.h>
#include <stdlib.h>
#include "printbin.h"

size_t bitcount(unsigned x);
int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	printf("%lu\n", bitcount(strtoul(argv[1], NULL, 10)));
	return 0;
}

/* How x & (x - 1) works:
 * 10011011 & 10011010 deletes rightmost bit
 * 10011010 & 10011001 deletes rightmost bit
 * Regardless of rightmost bit, subtracting 1 changes the LSB
 */
size_t bitcount(unsigned x)
{
	size_t b;
	for (b = 0; x > 0; x &= (x - 1))
		b++;
	return b;
}
