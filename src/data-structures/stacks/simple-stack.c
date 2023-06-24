/* Simple Dynamic Stack (sds) */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_SIZE 25

#include "simple-stack.h"
#include "../../utils/show.h"

SimpleStack * sds_create_stack() {
    SimpleStack *src = malloc(sizeof (SimpleStack));
    src->top = NULL;
    return src;
}

SimpleStackNode * sds_create_node(int value) {
    SimpleStackNode *src = malloc(sizeof (SimpleStackNode));
    src->value = value;
    return src;
}

void sds_push_node(SimpleStack *src, SimpleStackNode newNode) {
    SimpleStackElement *newElement = malloc(sizeof (SimpleStackElement));
    newElement->node = newNode;
    newElement->next = src->top;
    src->top = newElement;
}

SimpleStackNode sds_pop_node(SimpleStack *src) {
    SimpleStackElement *top = src->top;
    SimpleStackNode topNode = top->node;
    src->top = src->top->next;
    free(top);
    return topNode;
}

SimpleStackNode sds_peek_node(SimpleStack *src) {
    return src->top->node;
}

int sds_is_empty(SimpleStack *src) {
    return (src->top == NULL) ? 1 : 0;
}

void sds_print_stack(SimpleStack *src) {
    endline();
    endline();

    SimpleStackElement *crawler = src->top;
    char text[255];

    show_start(MAGENTA, BLACK);
    show_text_align_center("TOP", MAX_LINE_SIZE);
    show_close();
    endline();
    endline();

    if (sds_is_empty(src)) {
        show_start(BLUE, BLACK);
        sprintf(text, "NULL");
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();
        endline();
    }

    while (crawler != NULL) {
        show_start(BLUE, BLACK);
        sprintf(text, "node.value: %d", crawler->node.value);
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();


        show_start(BLUE, BLACK);
        if (crawler->next != NULL)
            sprintf(text, "next.node.value: %d", crawler->next->node.value);
        else
            sprintf(text, "next: NULL");
        show_text_align_center(text, MAX_LINE_SIZE);
        show_close();
        endline();

        endline();
        crawler = crawler->next;
    }

    show_close();
}

void sds_print_node(SimpleStackNode node) {
    endline();
    char text[255];
    show_start(BLUE, BLACK);
    sprintf(text, "value: %d", node.value);
    show_text_align_center(text, MAX_LINE_SIZE);
    show_close();
    endline();
    endline();
}
