#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
typedef struct Node {
    int dest;
    struct Node *next;
} Node;

// A structure to represent an adjacency list
typedef struct List {
    struct Node *head; // pointer to head node of list
} List;

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be vertex (number of vertices in graph)
typedef struct Graph {
    int vertex;
    struct List *array;
} Graph;

// A utility function to create a new adjacency list node
Node *createListNode(int dest) {
    Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of vertex vertices
Graph *createGraph(int V) {
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    graph->vertex = V;

    // Create an array of adjacency lists.  Size of array will be vertex
    graph->array = (List*) malloc(V * sizeof(List));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    Node* newNode = createListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
//    newNode = newAdjacencyListNode(src);
//    newNode->next = graph->array[dest].head;
//    graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(Graph* graph) {
    int v;
    for (v = 0; v < graph->vertex; ++v) {
        Node* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main() {
    int V = 5;
    Graph *graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}