/* Double Ended Queue (deck) */

#include <stdio.h>
#include <stdlib.h>

#include "deck.h"
#include "../../utils/show.h"

Deck * deck_create_queue() {
    Deck *new = malloc(sizeof (Deck));
    new->head = malloc(sizeof (DeckElement));
    new->head->next = NULL;
    new->head->previous = NULL;
    new->head->node = *deck_create_node(0);

    new->len = 0;
    return new;
}

DeckNode * deck_create_node(int value) {
    DeckNode *src = malloc(sizeof (DeckNode));
    src->value = value;
    return src;
}

int deck_is_empty(Deck *src) {
    return (src->head->next == NULL || src->head->previous == NULL);
}

int deck_start_exists(Deck *src) {
    return (src->head->next != NULL);
}

int deck_end_exists(Deck *src) {
    return (src->head->previous != NULL);
}

void deck_enqueue_node_at_start(Deck *src, DeckNode newNode) {
    DeckElement *newElement = malloc(sizeof (DeckElement));

    newElement->node = newNode;
    newElement->next = src->head->next;
    newElement->previous = src->head;
    newElement->next->previous = newElement;
    src->head->next = newElement;

    src->len++;
}

void deck_enqueue_node_at_end(Deck *src, DeckNode newNode) {
    DeckElement *newElement = malloc(sizeof (DeckElement));

    deck_print_element(src->head, "Deck Head");
    newElement->node = newNode;
    if (deck_start_exists(src))
        newElement->previous = src->head->next;
    else
        newElement->previous = src->head;

    newElement->next = src->head;
    src->head->previous = newElement;
    newElement->previous->next = newElement;


    src->len++;
}

DeckNode * deck_dequeue_node_at_start(Deck *src) {
    if (!deck_start_exists(src)) return NULL;

    DeckElement *first = src->head->next;
    DeckElement *out = src->head->next;

    src->head->next = first->next;
    first->next->previous = src->head;
    src->len--;

    free(first);
    return &out->node;
}

DeckNode * deck_dequeue_node_at_end(Deck *src) {
    if (!deck_end_exists(src)) return NULL;

    DeckElement *last = src->head->previous;
    DeckElement *out = src->head->previous;

    src->head->previous = last->previous;
    last->previous->next = src->head;
    src->len--;

    free(last);
    return &out->node;
}

void deck_print_queue(Deck *src) {
    endline();
    DeckElement *crawler = src->head;
    int lineSize = (src->len - 1) * 9 ;

    show_highlight(" HEAD ", BLUE, BLACK);
    printf(" --- ");

    if (deck_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    crawler = crawler->next;

    while (crawler != NULL && crawler->node.value != 0) {
        char text[255];
        sprintf(text, " %d ", crawler->node.value);
        show_highlight(text, CYAN, BLACK);

        crawler = crawler->next;
        if (crawler != NULL && crawler->node.value != 0) printf(" --- ");
    }
    endline();

    printf("   ⌊");
    show_repeated("_", lineSize);
    printf("⌋");
    endline();

}

void deck_print_node(DeckNode src, char *title) {
    endline();

    show_text(title, NORMAL);
    char text[255];
    sprintf(text, " %d ", src.value);
    show_highlight(text, WHITE, BLACK);

    endline();
}

void deck_print_element(DeckElement *src, char *title) {
    endline();
    show_text_ln(title, NORMAL);

    char text[255];
    sprintf(text, "    node.value: %d ", src->node.value);
    show_text(text, BLUE);

    if (src->next != NULL) {
        sprintf(text, "    next.node.value: %d ", src->next->node.value);
        show_text(text, BLUE);
    } else {
        show_text("    next: NULL ", BLUE);
    }

    if (src->previous != NULL) {
        sprintf(text, "    previous.node.value: %d ", src->previous->node.value);
        show_text(text, BLUE);
    } else {
        show_text("    previous: NULL ", BLUE);
    }

    endline();
}

void deck_print_as_stack(Deck *src) {
    endline();
    DeckElement *crawler = src->head;
    int lineSize = src->len * 8 + src->len;

    show_highlight_ln(" HEAD ", BLUE, BLACK);

    if (deck_is_empty(src)) {
        show_text_ln("NULL", BLUE);
        return;
    }

    char text[255];
    int next, previous;
    next = (crawler->next != NULL) ? crawler->next->node.value : 0;
    previous = (crawler->previous != NULL) ? crawler->previous->node.value : 0;

    sprintf(text, " [%2d] (next: %2d) (previous: %2d)", crawler->node.value, next, previous);
    show_text(text, CYAN);
    endline();

    crawler = crawler->next;
    while (crawler != NULL && crawler->node.value != 0) {

        next = (crawler->next != NULL) ? crawler->next->node.value : 0;
        previous = (crawler->previous != NULL) ? crawler->previous->node.value : 0;

        sprintf(text, " [%2d] (next: %2d) (previous: %2d)", crawler->node.value, next, previous);
        show_text(text, CYAN);

        crawler = crawler->next;
        endline();
    }
    endline();

    endline();
}