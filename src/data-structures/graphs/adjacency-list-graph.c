/* Adjacency List (Directed) Graph (algraph)
 *
 * Implemented using Dynamic Linked List (dyll) --> adjacency list (adjlist)
 *
 * We are creating two dynamic lists to represent our graph
 *
 * 1st list = graph nodes
 * 2nd list = node adjacency list (neighbours)
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include "../../utils/show.h"

typedef struct Node {
    int value;
} Node;

typedef struct AdjacencyListElement {
    Node node;
    struct AdjacencyListElement *next;
} AdjacencyListElement;

typedef struct AdjacencyList {
    AdjacencyListElement *head;
} AdjacencyList;

AdjacencyList * adjlist_create_list() {
    AdjacencyList *src = malloc(sizeof (AdjacencyList));
    src->head = NULL;
    return src;
}

Node * create_node(int value) {
    Node *src = malloc(sizeof (Node));
    src->value = value;
    return src;
}

int adjlist_get_len(AdjacencyList *src) {
    int len = 0;
    AdjacencyListElement *crawler = src->head;
    while (crawler != NULL) {
        len++;
        crawler = crawler->next;
    }
    return len;
}

/** ascending sorting */
AdjacencyListElement * adjlist_find_element_and_previous(AdjacencyList *src, int newValue, AdjacencyListElement **previous) {
    *previous = NULL;
    AdjacencyListElement *crawler = src->head;
    while (crawler != NULL && crawler->node.value < newValue) {
        *previous = crawler;
        crawler = crawler->next;
    }
    return (crawler != NULL && crawler->node.value == newValue) ? crawler : NULL;
}

/** insert in order */
int adjlist_insert_node(AdjacencyList *src, Node newNode) {
    int newValue = newNode.value;
    AdjacencyListElement *previous;
    AdjacencyListElement *crawler;

    crawler = adjlist_find_element_and_previous(src, newValue, &previous);
    if  (crawler != NULL) return 0;

    crawler = malloc(sizeof (AdjacencyListElement));
    crawler->node = newNode;

    if (previous == NULL) {
        crawler->next = src->head;
        src->head = crawler;
    } else {
        crawler->next = previous->next;
        previous->next = crawler;
    }

    return 1;
}

int adjlist_delete_node(AdjacencyList *src, int valueTarget) {
    AdjacencyListElement *previous;
    AdjacencyListElement *crawler;

    crawler = adjlist_find_element_and_previous(src, valueTarget, &previous);

    if (crawler == NULL) return 0;

    if (previous == NULL) {
        src->head = crawler->next;
    } else {
        previous->next = crawler->next;
    }

    free(crawler);
    return 1;
}

int adjlist_is_empty(AdjacencyList *src) {
    return (src->head == NULL) ? 1 : 0;
}

AdjacencyListElement * adjlist_find_one(AdjacencyList *src, int valueTarget) {
    AdjacencyListElement *crawler = src->head;
    while (crawler != NULL) {
        if (crawler->node.value == valueTarget) return crawler;
        crawler = crawler->next;
    }
    return NULL;
}

void adjlist_print_list(AdjacencyList *src) {
    AdjacencyListElement *crawler = src->head;
//    show_text_ln("Adjacency list: ", MAGENTA);

    if (adjlist_is_empty(src)) {
        show_text("NULL", MAGENTA);
    }

    while (crawler != NULL) {
        char text[255];
        sprintf(text, " %d ", crawler->node.value);
        show_highlight(text, MAGENTA, BLACK);
        crawler = crawler->next;
        if (crawler != NULL)
            printf(" -- ");
    }
    endline();
}

typedef struct GraphNode {
    Node node;
    struct AdjacencyList *neighbours;
    struct GraphNode *next;
} GraphNode;

typedef struct Graph {
    GraphNode *nodesHead;
} Graph;

Graph * algraph_create_graph() {
    Graph *graph = malloc(sizeof (Graph));
    graph->nodesHead = NULL;
    return graph;
}

/** not sorting */
GraphNode * algraph_find_element_and_previous(Graph *src, int newValue, GraphNode **previous) {
    *previous = NULL;
    GraphNode *crawler = src->nodesHead;
    while (crawler != NULL) {
        *previous = crawler;
        crawler = crawler->next;
    }
    return crawler;
}

/** insert in order */
int algraph_insert_node(Graph *src, Node newNode) {
    int newValue = newNode.value;
    GraphNode *previous;
    GraphNode *newGraphNode;

    newGraphNode = algraph_find_element_and_previous(src, newValue, &previous);
    if  (newGraphNode != NULL) return 0;

    newGraphNode = malloc(sizeof (GraphNode));
    newGraphNode->node = newNode;
    newGraphNode->neighbours = malloc(sizeof (AdjacencyList));
    newGraphNode->neighbours->head = NULL;

    if (previous == NULL) {
        newGraphNode->next = src->nodesHead;
        src->nodesHead = newGraphNode;
    } else {
        newGraphNode->next = previous->next;
        previous->next = newGraphNode;
    }

    return 1;
}

void algraph_print_nodes(Graph *src) {
    GraphNode *crawler = src->nodesHead;
    show_text_ln("Graph Nodes: ", MAGENTA);
    while (crawler != NULL) {
        char text[255];
        sprintf(text, " %d ", crawler->node.value);
        show_highlight(text, MAGENTA, BLACK);
        crawler = crawler->next;
        if (crawler != NULL)
            printf(" -- ");
    }
    endline();
}

void algraph_insert_edge(Graph *graph, Node src, Node dest) {
    GraphNode *crawler = graph->nodesHead;

    while (crawler != NULL && crawler->node.value != src.value) {
        crawler = crawler->next;
    }

    if (crawler == NULL) return;

    adjlist_insert_node(crawler->neighbours, dest);
}

void algraph_print_node_adjlist(Graph *graph, Node src) {
    GraphNode *crawler = graph->nodesHead;
    char text[255];
    sprintf(text, " %d ", src.value);
    show_highlight(text, BLUE, BLACK);
    show_text(" -- ", NORMAL);
    while (crawler != NULL && crawler->node.value != src.value) {
        crawler = crawler->next;
    }
    if (crawler == NULL) return;
    adjlist_print_list(crawler->neighbours);
}

void algraph_print_graph(Graph *graph) {
    GraphNode *crawler = graph->nodesHead;
    endline();
    show_text_ln("Graph", MAGENTA);
    char text[255];
    while (crawler != NULL) {
        sprintf(text, " %d ", crawler->node.value);
        show_highlight(text, BLUE, BLACK);
        show_text(" -- ", NORMAL);
        adjlist_print_list(crawler->neighbours);
        crawler = crawler->next;
        endline();
    }
}

void init_main() {
    init_show();
}

int main() {
    init_main();

    show_header("Adjacency List Graph - Implementation", BLUE);
    Graph *graph = algraph_create_graph();
    Node *a = create_node(10);
    Node *b = create_node(32);
    Node *c = create_node(45);

    algraph_insert_node(graph, *a);
    algraph_insert_node(graph, *b);
    algraph_insert_node(graph, *c);
    algraph_print_graph(graph);

//    algraph_print_nodes(graph);

    algraph_insert_edge(graph, *a, *b);
    algraph_insert_edge(graph, *a, *c);
    algraph_print_graph(graph);
//    algraph_print_node_adjlist(graph, *a);

    algraph_insert_edge(graph, *c, *a);
    algraph_print_graph(graph);
//    algraph_print_node_adjlist(graph, *c);

    return 0;
}