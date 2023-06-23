/* Doubled Dynamic Linked List (dobll) */

#include <stdio.h>
#include <stdlib.h>

#include "../libs/doubled-linked-list.h"
#include "../../utils/show.h"

typedef struct DobllNode {
    int value;
} DobllNode;

typedef struct DobllElement {
    DobllNode node;
    struct DobllElement *next;
    struct DobllElement *previous;
} DobllElement;

typedef struct DoubledLinkedList {
    DobllElement *head;
} DoubledLinkedList;

DoubledLinkedList * dobll_create_linked_list() {
    DoubledLinkedList *src = malloc(sizeof (DoubledLinkedList));

    dobll_init_list(src);

    return src;
}

DobllNode * dobll_create_node(int value) {
    DobllNode *src = malloc(sizeof (DobllNode));

    src->value = value;

    return src;
}

void dobll_init_list(DoubledLinkedList *src) {
    src->head = NULL;
}

int dobll_get_valid_elements(DoubledLinkedList *src) {
    int len = 0;
    DobllElement *crawler = src->head;

    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }

    return len;
}

void dobll_print_list(DoubledLinkedList *src) {
    DobllElement *crawler = src->head;

    show_title("Doubled Linked List");

    while (crawler != NULL) {
        dobll_print_element(crawler);

        crawler = crawler->next;
    }
}

void dobll_print_element(DobllElement *src) {
    show_subtitle("Linked List DyllElement");

    show_attr_int("node.value", src->node.value);

    if (src->next != NULL)
        show_attr_int("next.node.value", src->next->node.value);
    else
        show_attr_str("next.node.value", "NULL");

    if (src->previous != NULL)
        show_attr_int("previous.node.value", src->previous->node.value);
    else
        show_attr_str("previous.node.value", "NULL");
}

DobllElement * dobll_find_one(DoubledLinkedList *src, int valueTarget) {
    DobllElement *crawler = src->head;

    while (crawler != NULL) {
        if (crawler->node.value == valueTarget) return crawler;

        crawler = crawler->next;
    }

    return NULL;
}

DobllElement * dobll_find_element_and_previous(DoubledLinkedList *src, int newValue, DobllElement **previous) {
    *previous = NULL;

    DobllElement *crawler = src->head;

    while (crawler != NULL && crawler->node.value < newValue) {
        *previous = crawler;
        crawler = crawler->next;
    }

    if (crawler != NULL && crawler->node.value == newValue) return crawler;

    return NULL;
}

int dobll_insert_node(DoubledLinkedList *src, DobllNode *newDobllNode) {
    int newValue = newDobllNode->value;
    DobllElement *previous;
    DobllElement *crawler;

    crawler = dobll_find_element_and_previous(src, newValue, &previous);

    if (crawler != NULL) return 0;

    crawler = malloc(sizeof (DobllElement));

    crawler->node = *newDobllNode;

    if (previous == NULL) {
        /* insert on 1st position */
        show_subtitle("trying to insert node");
        crawler->previous = NULL;
        crawler->next = src->head;

        src->head = crawler;
    } else if (previous->next == NULL) {
        /* insert on last position */
        crawler->previous = previous;
        crawler->next = previous->next;

        previous->next = crawler;
    } else {
        crawler->next = previous->next;
        crawler->previous = previous;

        previous->next->previous = crawler;
        previous->next = crawler;
    }

    return 1;
}

int dobll_delete_node(DoubledLinkedList *src, int valueTarget) {
    DobllElement *previous;
    DobllElement *crawler;

    crawler = dobll_find_element_and_previous(src, valueTarget, &previous);

    if (crawler == NULL) return 0;

    if (previous == NULL) {
        src->head = crawler->next;
    } else {
        previous->next = crawler->next;
    }

    free(crawler);
    return 1;
}

void dobll_restart_list(DoubledLinkedList *src) {
    DobllElement *crawler = src->head;

    while (crawler != NULL) {
        DobllElement *target = crawler;
        crawler = crawler->next;

        free(target);
    }

    src->head = NULL;
}