/*
 * Double Ended Queue (deck)
 *
 * Implemented using Doubled Loop Linked List (dobll) + Simple Queue (sq)
 *
 * Basic operations for queue: create, enqueue, dequeue, isEmpty, isFull, size
 *
 * */

typedef struct DeckNode {
    int value;
} DeckNode;

typedef struct DeckElement {
    DeckNode node;
    struct DeckElement *next;
    struct DeckElement *previous;
} DeckElement;

typedef struct Deck {
    DeckElement *head;
    int len;
} Deck;

Deck * deck_create_queue();
DeckNode * deck_create_node(int value);

int deck_is_empty(Deck *src);

void deck_enqueue_node_at_start(Deck *src, DeckNode newNode);
void deck_enqueue_node_at_end(Deck *src, DeckNode newNode);
DeckNode * deck_dequeue_node(Deck *src);

DeckNode * deck_dequeue_node_at_start(Deck *src);
DeckNode * deck_dequeue_node_at_end(Deck *src);

void deck_print_queue(Deck *src);
void deck_print_as_stack(Deck *src);
void deck_print_node(DeckNode src, char *title);
void deck_print_element(DeckElement *src, char *title);