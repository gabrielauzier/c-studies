#include "simple-stack.h"
#include "../../utils/show.h"

void init_main() {
    init_show();
}

int main() {
    init_main();

    show_header("Simple Dynamic Stack - Implementation", MAGENTA);

    SimpleStackNode node;
    SimpleStack *stack = sds_create_stack();
    SimpleStackNode *a = sds_create_node(10);
    SimpleStackNode *b = sds_create_node(32);
    SimpleStackNode *c = sds_create_node(94);

    show_text("Stack 0", MAGENTA);
    sds_print_stack(stack);

    show_text("Stack 1 - pushing", MAGENTA);
    sds_push_node(stack, *a);
    sds_print_stack(stack);

    show_text("Stack 2 - pushing", MAGENTA);
    sds_push_node(stack, *b);
    sds_print_stack(stack);

    show_text("Stack 3 - pushing", MAGENTA);
    sds_push_node(stack, *c);
    sds_print_stack(stack);

    show_text("Stack 4 - popping", MAGENTA);
    node = sds_pop_node(stack);
    sds_print_stack(stack);

    show_text_ln("Node - popped", BLUE);
    sds_print_node(node);

    show_text("Stack 5 - peeking", MAGENTA);
    node = sds_peek_node(stack);
    sds_print_stack(stack);

    show_text_ln("Node - peeked", BLUE);
    sds_print_node(node);

    return 0;
}