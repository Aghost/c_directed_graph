/*
 * DIRECTED GRAPH IMPLEMENTATION
 * BASE FROM: https://www.techiedelight.com/implement-graph-data-structure-c
 */

#include <stdio.h>
#include <stdlib.h>

#define N 6  //max number of vertices in graph

struct Graph {
    struct Node* head[N];   // Array of pointers
};

struct Node {
    int dest;
    struct Node* next;
    // long int id ?
    // struct Data* ?
};

struct Edge {
    int src, dest;
    // long int id ?
};


// CREATE GRAPH
struct Graph* createGraph(struct Edge edges[], int n) {

    // allocate storage for graph data structure
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));

    for (unsigned i = 0; i < n; i++) {  //initialize head pointer for all vertices
        int src = edges[i].src;         //get the source and destination vertex
        int dest = edges[i].dest;

        /*
        printf("Graph head: %d, %d, %d\n", graph->head[i], graph->head[src], graph->head[dest]);
        printf("edges[%d].src = %d, ", i, &edges[i].src);
        printf("edges[%d].dest = %d\n", i, &edges[i].dest);
        */

        // Allocate a new node of adjacency list from src to dest
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph->head[src];
        graph->head[src] = newNode;
    }

    return graph;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < N; i++) {
        struct Node* ptr = graph->head[i];
        while (ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        putchar('\n');
    }
}
