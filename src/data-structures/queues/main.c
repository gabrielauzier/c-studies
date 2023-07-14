#include <stdio.h>
#include <stdlib.h>

#include "../../utils/show.h"
#include "simple-queue.h"
#include "deck.h"

void init_main_() {
    init_show();
}

void simple_queue() {
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

}

void deck() {
    show_header("Data structure - Deck", BLUE);
    Deck *deck = deck_create_queue();

    DeckNode *a = deck_create_node(12);
    DeckNode *b = deck_create_node(43);
    DeckNode *c = deck_create_node(27);
    DeckNode *d = deck_create_node(85);

    show_text_ln("Deck 0", BLUE);
    deck_print_queue(deck);
    endline();

    show_text_ln("Deck 1 - enqueue 3 at end", BLUE);
    deck_enqueue_node_at_end(deck, *a);
    deck_enqueue_node_at_end(deck, *b);
    deck_enqueue_node_at_end(deck, *c);
    deck_print_queue(deck);
    deck_print_as_stack(deck);
    endline();

    show_text_ln("Deck 2 - enqueue 1 at start", BLUE);
    deck_enqueue_node_at_start(deck, *d);
    deck_print_queue(deck);
    deck_print_as_stack(deck);
    endline();

    show_text_ln("Deck 3 - dequeue at start", BLUE);
    deck_dequeue_node_at_start(deck);
    deck_print_queue(deck);
    deck_print_as_stack(deck);
    endline();


    show_text_ln("Deck 4 - dequeue at end", BLUE);
    deck_dequeue_node_at_end(deck);
    deck_print_queue(deck);
    endline();
}

int main() {
    init_main_();
    deck();

    return 0;
}