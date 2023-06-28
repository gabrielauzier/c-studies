/* Arithmetic Expression (artexp) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_CHAR 255

typedef char Expression[MAX_CHAR];

typedef struct ArithmeticExpression ArithmeticExpression;

ArithmeticExpression * create_arithmetic_expression(char *expInfix);
void artexp_print_expression(ArithmeticExpression *src);
void artexp_delete_expression(ArithmeticExpression *src);

char * artexp_infix_to_postfix(char *infix);
char * artexp_infix_to_prefix(char *infix);

int artexp_evaluate_postfix(char *postfix);
int artexp_evaluate_prefix(char *prefix);