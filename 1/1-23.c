#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char **argv)
{
	int c;
	char linecomment = 0;
	char multicomment = 0;

	while ((c = getchar()) > EOF) {
		int next;
		switch (c) {
		case '/':
			next = getchar(); // This is an endline comment
			switch (next) {
			case '/':
				linecomment = 1; /* This here is a multi-line
						  * comment, to just take
						  * up a lot of space!
						  */ break;
			case '*':
				multicomment = 1;
				break;
			default:
				ungetc(next, stdin);
				putchar(c);
				break;
			}
			break;
		case '\n':
			if (linecomment)
				linecomment = 0;
			if (!linecomment & !multicomment)
				putchar(c);
			break;
		case '*':
			next = getchar();
			if (next == '/') {
				multicomment = 0;
			} else {
				ungetc(next, stdin);
				if (!linecomment & !multicomment)
					putchar(c);
			}
			break;
		default:
			if (linecomment | multicomment)
				continue;
			else
				putchar(c);
		}
	}
}

/* I like to use this source code as a test for the program */
