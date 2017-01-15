#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192
int escape(char *dest, const char *src, size_t n);
int descape(char *dest, const char *src, size_t n);
int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	char esc = strcmp(argv[1], "esc");
	char desc = strcmp(argv[1], "desc");
	int (*f)(char *, const char *, size_t);
	if (!esc) {
		f = escape;
	} else if (!desc) {
		f = descape;
	} else {
		printf("usage: 3-2 [esc | desc]");
		return 1;
	}
	char dest[SIZE];
	char src[SIZE];
	int c = 0;
	size_t i;
	do {
		i = 0;
		while ((c = getchar()) > EOF && i < SIZE)
			src[i++] = c;
		src[i] = '\0';
		f(dest, src, SIZE);
		printf("%s\n", dest);
	} while (c > EOF);
	return 0;
}

int escape(char *dest, const char *src, size_t n)
{
	if (!dest || !src)
		return 1;
	size_t i1 = 0;
	size_t i2 = 0;
	for (i1 = 0, i2 = 0; i1 < n && src[i2] > '\0'; i2++) {
		switch(src[i2]) {
		case '\\':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = '\\';
			break;
		case '\'':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = '\'';
			break;
		case '\"':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = '\"';
			break;
		case '\a':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'a';
			break;
		case '\b':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'b';
			break;
		case '\e':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'e';
			break;
		case '\f':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'f';
			break;
		case '\n':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'n';
			break;
		case '\r':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'r';
			break;
		case '\t':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 't';
			break;
		case '\v':
			dest[i1++] = '\\';
			if (i1 < n)
				dest[i1++] = 'v';
			break;
		default:
			dest[i1++] = src[i2];
			break;
		}
	}
	dest[i1] = '\0';
	return 0;
}

int descape(char *dest, const char *src, size_t n)
{
	if (!dest || !src)
		return 1;
	size_t i1 = 0;
	size_t i2 = 0;
	for (i1 = 0, i2 = 0; i1 < n && src[i2] > '\0'; i2++) {
		if (src[i2] == '\\') {
			switch(src[i2+1]) {
			case '\\':
				i2++;
				dest[i1++] = '\\';
				break;
			case '\'':
				i2++;
				dest[i1++] = '\'';
				break;
			case '\"':
				i2++;
				dest[i1++] = '\"';
				break;
			case 'a':
				i2++;
				dest[i1++] = '\a';
				break;
			case 'b':
				i2++;
				dest[i1++] = '\b';
				break;
			case 'e':
				i2++;
				dest[i1++] = '\e';
				break;
			case 'f':
				i2++;
				dest[i1++] = '\f';
				break;
			case 'n':
				i2++;
				dest[i1++] = '\n';
				break;
			case 'r':
				i2++;
				dest[i1++] = '\r';
				break;
			case 't':
				i2++;
				dest[i1++] = '\t';
				break;
			case 'v':
				i2++;
				dest[i1++] = '\v';
				break;
			default:
				dest[i1++] = src[i2++];
				dest[i1++] = src[i2];
				break;
			}
		} else {
			dest[i1++] = src[i2];
		}
	}
	return 0;
}
