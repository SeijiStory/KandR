#include <stdio.h>
#include "reverse.h"

#define SIZE 16
#define SMALLEST ((unsigned)(~0) ^ ((unsigned)(~0) >> 1))

void itoa(int n, char s[]);
int main(int argc, char **argv)
{
	char str[SIZE];
	signed i = SMALLEST;
	itoa(i, str);
	printf("%d\n%s\n", i, str);
	i++;
	itoa(i, str);
	printf("%d\n%s\n", i, str);
	return 0;
}

/* The original itoa() does not work with the smallest number
 * (i.e. (~0) ^ ((unsigned)(~0) >> 1))
 * Example using 1-byte word size: *	           -x = ~x + 1
 *	-(0b10000000) = ~0b10000000 + 1
 *	              = 0b01111111 + 1
 *	              = 0b11111111
 *	              = -1
 */
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i;
	int sign;
	char toobig;
	/* If the two's compliment of n is invalid */
	if (n == (signed)SMALLEST) {
		n = n + 1;
		toobig = 1;
	}
	if ((sign = n) < 0) /* record sign */
		n = -n;
	i = 0;
	do {
		/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
		if (toobig) { /* Get the right number */
			s[i-1] += 1;
			toobig = 0;
		}
	} while ((n /= 10) > 0);
	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
