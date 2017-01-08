#include <stdio.h>

unsigned int htoi(const char *nptr);
unsigned long htol(const char *nptr);
unsigned long long htoll(const char *nptr);
signed char scandigit(const char c);

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	printf("%u\n", htoi(argv[1]));
	printf("%lu\n", htol(argv[1]));
	printf("%llu\n", htoll(argv[1]));
	return 0;
}

signed char scandigit(const char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	return -1;
}

unsigned int htoi(const char *nptr)
{
	unsigned char i = 0;
	unsigned char max = sizeof(int) * 2;
	unsigned int val = 0;

	if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X')) {
		i = 2;
		max += 2;
	}
	for (i; nptr[i] > '\0' && i <= max; ++i) {
		signed char d = scandigit(nptr[i]);
		if (d < 0)
			return 0;
		val *= 0x10;
		val += d;
	}
	return val;
}

unsigned long htol(const char *nptr)
{
	unsigned char i = 0;
	unsigned char max = sizeof(long) * 2;
	unsigned long val = 0;

	if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X')) {
		i = 2;
		max += 2;
	}
	for (i; nptr[i] > '\0' && i <= max; ++i) {
		signed char d = scandigit(nptr[i]);
		if (d < 0)
			return 0;
		val *= 0x10;
		val += d;
	}
	return val;
}

unsigned long long htoll(const char *nptr)
{
	unsigned char i = 0;
	unsigned char max = sizeof(long long) * 2;
	unsigned long long val = 0;

	if (nptr[0] == '0' && (nptr[1] == 'x' || nptr[1] == 'X')) {
		i = 2;
		max += 2;
	}
	for (i; nptr[i] > '\0' && i <= max; ++i) {
		signed char d = scandigit(nptr[i]);
		if (d < 0)
			return 0;
		val *= 0x10;
		val += d;
	}
	return val;
}
