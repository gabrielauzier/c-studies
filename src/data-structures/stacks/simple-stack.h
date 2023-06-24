/*
 * Simple Dynamic Stack (sds)
 *
 * Basic operations for stack: push, pop, isEmpty, isFull, peek (without removing)
 *
 * */

typedef struct SimpleStackNode {
    int value;
} SimpleStackNode;

typedef struct SimpleStackElement {
    SimpleStackNode node;
    struct SimpleStackElement *next;
} SimpleStackElement;

typedef struct SimpleStack {
    SimpleStackElement *top;
} SimpleStack;

SimpleStack * sds_create_stack();
SimpleStackNode * sds_create_node(int value);

void sds_push_node(SimpleStack *src, SimpleStackNode newNode);
SimpleStackNode sds_pop_node(SimpleStack *src);
SimpleStackNode sds_peek_node(SimpleStack *src);

int sds_is_empty(SimpleStack *src);

void sds_print_stack(SimpleStack *src);
void sds_print_node(SimpleStackNode node);