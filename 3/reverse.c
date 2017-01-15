#include <string.h>

/* reverse: reverse string s in place */
int reverse(char *s)
{
	if (!s)
		return 1;
	size_t i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			s[i] ^= s[j];
			s[j] ^= s[i];
			s[i] ^= s[j];
		}
	}
	return 0;
}
