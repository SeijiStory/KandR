#include <stdio.h>
#include <stdlib.h>

enum match { BRACE, BRACKET, PAREN, DQUOTE, SQUOTE, COMMENT, ESCAPE, NONE };


int printe(const char *format, ...);
int main (int argc, char **argv)
{
	int c;

	long long braces = 0;
	long long brackets = 0;
	long long parens = 0;

	char indquote = 0;
	char insquote = 0;
	char inlinecomment = 0;
	char incomment = 0;
	char escerr = 0;

	while ((c = getchar()) > EOF) {
		int next;
		switch (c) {
		case '{':
			if (!(incomment & !inlinecomment))
				braces++;
			break;
		case '}':
			if (!(incomment & !inlinecomment))
				braces--;
			break;
		case '[':
			if (!(incomment & !inlinecomment))
				brackets++;
			break;
		case ']':
			if (!(incomment & !inlinecomment))
				brackets--;
			break;
		case '(':
			if (!(incomment & !inlinecomment))
				parens++;
			break;
		case ')':
			if (!(incomment & !inlinecomment))
				parens--;
			break;
		case '\\':
			switch (next) {
			/* Not going to handle the octal or hex escapes today */
			case '0': case 'a': case 'b': case 't': case 'n':
			case 'v': case 'f': case 'r': case '\'': case '\"':
			case '\\': case '\?':
				continue;
			default:
				ungetc(next, stdin);
				escerr = 1;
				break;
			}
			break;
		case '\"':
			if (!(incomment & !inlinecomment))
				indquote = !indquote;
			break;
		case '\'':
			if (!(incomment & !inlinecomment))
				insquote = !insquote;
			break;
		case '/':
			if (inlinecomment)
				break;
			next = getchar();
			if (next == '*')
				incomment = 1;
			else if (next == '/')
				inlinecomment = 1;
			break;
		case '*':
			if (inlinecomment)
				break;
			next = getchar();
			if (next == '/')
				incomment = 0;
			else
				ungetc(next, stdin);
		case '\n':
			if (inlinecomment)
				inlinecomment = 0;
			break;
		default:
			continue;
		}
	}
	if (braces > 0)
		fprintf(stderr, "ERROR: too many braces\n");
	if (brackets > 0)
		fprintf(stderr, "ERROR: too many brackets\n");
	if (parens > 0)
		fprintf(stderr, "ERROR: too many parentheses\n");
	if (indquote)
		fprintf(stderr, "ERROR: unclosed double quote\n");
	if (insquote)
		fprintf(stderr, "ERROR: unclosed single quote\n");
	if (incomment)
		fprintf(stderr, "ERROR: unclosed multiline comment\n");
	if (escerr)
		fprintf(stderr, "ERROR: improperly formatted escape "
			"character\n");
	return (braces > 0) | (brackets > 0) | (parens > 0) |
		indquote | insquote | incomment | escerr;
}
