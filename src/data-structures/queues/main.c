#include <stdio.h>
#include <stdlib.h>

#include "../../utils/show.h"
#include "simple-queue.h"

void init_main_() {
    init_show();
}

int main() {
    init_main_();

    show_header("Data structure - Simple (Dynamic) Queue ", BLUE);

    SimpleQueue *queue = sq_create_queue();
    SimpleQueueNode *a = sq_create_node(12);
    SimpleQueueNode *b = sq_create_node(42);
    SimpleQueueNode *c = sq_create_node(61);

    sq_print_queue(queue);

    sq_enqueue_node(queue, *a);
    sq_enqueue_node(queue, *b);
    sq_enqueue_node(queue, *c);

    sq_print_queue(queue);

    SimpleQueueNode *node;

    node = sq_dequeue_node(queue);
    sq_print_node(node, "Dequeued =  ");
    sq_print_queue(queue);

    node = sq_dequeue_node(queue);
    sq_print_node(node, "Dequeued =  ");
    sq_print_queue(queue);

    node = sq_dequeue_node(queue);
    sq_print_node(node, "Dequeued =  ");
    sq_print_queue(queue);

    return 0;
}