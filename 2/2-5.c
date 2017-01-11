#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t any(const char *base, const char *src);
int charcmp(const void *a, const void *b);
ssize_t search(const void *key, const void *base,
	   size_t nmemb, size_t size,
	   int (*cmp)(const void *, const void *));

int main(int argc, char **argv)
{
	if (argc < 3)
		return 1;
	printf("%ld\n", any(argv[1], argv[2]));
	return 0;
}

ssize_t any(const char *base, const char *src)
{
	ssize_t index;
	size_t j;
	for (j = 0; src[j] > '\0'; ++j)
		if ((index = search(src+j, base, strlen(base), 1,
				    &charcmp)) > -1)
			return index;
	return -1;
}

int charcmp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

/* Have to use binary search to get specific index (i.e. must be unsorted) */
ssize_t search(const void *key, const void *base,
	   size_t nmemb, size_t size,
	   int (*cmp)(const void *, const void *))
{
	ssize_t i;
	for (i = 0; i < (ssize_t)nmemb; ++i) {
		signed char result = cmp(key, ((char *)base)+(size*i));
		if (!result)
			return i;
	}
	return -1;
}

/* A cheeky version of the any() function: */
/*
ssize_t any(const char *base, const char *src)
{
	char *result = strpbrk(base, src);
	if (result)
		return result - base;
	return -1;
}
*/
