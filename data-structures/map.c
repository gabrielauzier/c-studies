#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    char *value;
} Node;

typedef struct ListNode {
    Node *node;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode *head;
} List;

typedef struct Graph {
    int size;
    List *array;
} Graph;

Node *createNode(int key, char *value) {
    Node *result = malloc(sizeof (Node));

    result->key = key;
    result->value = value;

    return result;
}

Graph *createGraph(int size) {
    Graph *graph = malloc(sizeof(Graph));
    graph->size = size;

    graph->array = malloc(size * sizeof (List));

    for (int i = 0; i < size; ++i)
        graph->array[i].head = NULL;

    return graph;
}

ListNode *createListNode(Node *node) {
    ListNode *result = malloc(sizeof(ListNode));

    result->node = node;
    result->next = NULL;

    return result;
}

void addEdge(Graph *graph, Node *src, Node *dest) {

    if (graph->array[src->key].head == NULL) {
        ListNode *header = createListNode(src);
        header->next = graph->array[src->key].head;
        graph->array[src->key].head = header;
    }

    ListNode *newNode = createListNode(dest);
    newNode->next = graph->array[src->key].head;
    graph->array[src->key].head = newNode;
}

void printGraph(Graph *graph) {
    for (int key = 0; key < graph->size; ++key) {
        ListNode *pCrawl = graph->array[key].head;
        printf("\nAdjacency list of vertex\n head ");

        while(pCrawl) {
            printf("<- %s ", pCrawl->node->value);
            pCrawl = pCrawl -> next;
        }

        printf("[%d]\n", key);
    }
}

int main()
{
    Node *directory = createNode(0, "src");
    Node *directory2 = createNode(1, "projects");
    Node *file = createNode(2, "test.txt");
    Node *file2 = createNode(3, "test.txt");

    Graph *graph = createGraph(3);

    addEdge(graph, directory, directory2);
    addEdge(graph, directory, file);
    addEdge(graph, directory2, file2);

    printGraph(graph);

    return 0;
}