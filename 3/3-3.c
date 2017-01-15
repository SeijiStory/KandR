#include <stdio.h>

#define SIZE 8192
int expand(const char *s1, char *s2, size_t n);
int main(int argc, char **argv) {
	if (argc < 2)
		return 1;
	char string[SIZE];
	int i;
	for (i = 1; i < argc; ++i) {
		expand(argv[i], string, SIZE);
		printf("%s ", string);
	}
	printf("\n");
	return 0;
}

int expand(const char *s1, char *s2, size_t n)
{
	if (!s1 | !s2)
		return 1;
	size_t i1;
	size_t i2;
	for (i1 = 0, i2 = 0; i2 < n && s1[i1] > '\0'; ++i1) {
		char j;
		if (s1[i1] == '-') {
			if (i1 > 0
			    && s1[i1+1] > '\0'
			    && s1[i1+1] != '\t'
			    && s1[i1+1] != '\n') {
				char lower = s1[i1-1];
				char upper = s1[i1+1];
				for (j = lower + 1; j < upper; ++j)
					if (i2 < n)
						s2[i2++] = j;
			} else {
				s2[i2++] = s1[i1];
			}
		} else {
			s2[i2++] = s1[i1];
		}
	}
	s2[i2] = '\0';
	return 0;
}
