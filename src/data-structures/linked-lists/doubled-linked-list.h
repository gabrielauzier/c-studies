/* Doubled Dynamic Linked List (dobll) */

#include <stdio.h>
#include <stdlib.h>

typedef struct DobllNode DobllNode;
typedef struct DobllElement DobllElement;
typedef struct DoubledLinkedList DoubledLinkedList;

DoubledLinkedList * dobll_create_linked_list();
DobllNode * dobll_create_node(int value);

void dobll_init_list(DoubledLinkedList *src);
int dobll_get_valid_elements(DoubledLinkedList *src);

void dobll_print_list(DoubledLinkedList *src);
void dobll_print_element(DobllElement *src);

DobllElement * dobll_find_one(DoubledLinkedList *src, int valueTarget);
DobllElement * dobll_find_element_and_previous(DoubledLinkedList *src, int newValue, DobllElement **previous);

int dobll_insert_node(DoubledLinkedList *src, DobllNode *newDobllNode);
int dobll_delete_node(DoubledLinkedList *src, int valueTarget);
void dobll_restart_list(DoubledLinkedList *src);
