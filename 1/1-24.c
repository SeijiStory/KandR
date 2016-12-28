#include <stdio.h>
#include <stdlib.h>

enum match { BRACE, BRACKET, PAREN, DQUOTE, SQUOTE, COMMENT, ESCAPE, NONE };
struct match_list {
	enum match data;
	struct list *next;
};
struct match_list *list_new(void);
enum match car(struct match_list list);
struct match_list *cdr(struct match_list list);

struct stack {
	struct match_list stack;
};
struct stack *stack_new(void);
void push(struct stack *stack, enum match x);
enum match pop(struct stack *stack);

int main (int argc, char **argv)
{
	int c;
	struct stack *stack = stack_new();
	while ((c = getchar()) > EOF) {
		switch (c) {
		case '{':
			push(stack, BRACE);
		case '[':
			push(
		case '(':
		}
	}
}
