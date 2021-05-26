#include<stdio.h>
#include "graph.c"

int main(int argc, char* argv[]) {
    printf("test\n");

    struct Edge edges[] = {
        {0,1}, {1,2}, {2,0}, {2,1}, {3,2}, {4,5}, {5,4}, {0,3}, {3,0}
    };

    int n = sizeof(edges)/sizeof(edges[0]);
    struct Graph *graph = createGraph(edges, n);

    printGraph(graph);

    return 0;
}
