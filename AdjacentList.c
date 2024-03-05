#include <stdio.h>
#include <stdlib.h>

// Node structure for an individual vertex in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the entire graph
struct Graph {
    int vertices;
    struct Node** adjacencyList;
};

// Function to create a new node for a vertex
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}
void addEdge(struct Graph* graph, int startVertex, int endVertex) {
    if (startVertex >= 0 && startVertex < graph->vertices && endVertex >= 0 && endVertex < graph->vertices) {
        struct Node* newNode = createNode(endVertex);
        newNode->next = graph->adjacencyList[startVertex];
        graph->adjacencyList[startVertex] = newNode;

        newNode = createNode(startVertex);
        newNode->next = graph->adjacencyList[endVertex];
        graph->adjacencyList[endVertex] = newNode;
    } else {
        printf("Invalid vertices. Please provide valid vertex indices.\n");
    }
}
void displayGraph(struct Graph* graph) {
    printf("Adjacency List:\n");
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* current = graph->adjacencyList[i];
        printf("Vertex %d:", i);
        while (current != NULL) {
            printf(" -> %d", current->vertex);
            current = current->next;
        }
        printf(" -> NULL\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* current = graph->adjacencyList[i];
        while (current != NULL) {
            struct Node* nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
    free(graph->adjacencyList);
    free(graph);
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

    // Free the memory used by the graph
    freeGraph(myGraph);

    return 0;
}
