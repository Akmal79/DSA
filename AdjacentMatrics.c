#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    if (startVertex >= 0 && startVertex < graph->vertices && endVertex >= 0 && endVertex < graph->vertices) {
        graph->adjacencyMatrix[startVertex][endVertex] = 1;
        graph->adjacencyMatrix[endVertex][startVertex] = 1;
    } else {
        printf("Invalid vertices. Please provide valid vertex indices.\n");
    }
}
void displayGraph(struct Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct Graph* myGraph = createGraph(vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (vertex pairs) in the graph:\n");
    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);
        addEdge(myGraph, startVertex, endVertex);
    }

    displayGraph(myGraph);

    for (int i = 0; i < vertices; i++) {
        free(myGraph->adjacencyMatrix[i]);
    }
    free(myGraph->adjacencyMatrix);
    free(myGraph);

    return 0;
}
