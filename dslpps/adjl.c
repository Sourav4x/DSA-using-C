#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};


struct AdjList {
    struct Node* head;
};


struct Graph {
    int numVertices;
    struct AdjList* array;
};


struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}


void addEdgeUndirected(struct Graph* graph, int src, int dest) {
    
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}


void addEdgeDirected(struct Graph* graph, int src, int dest) {
    
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->array[vertex].head;
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}


void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0;
    }

    struct Node* queue = NULL;
    struct Node* temp = NULL;

    printf("BFS Traversal starting from vertex %d: ", startVertex);
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    enqueue(&queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(&queue);

        temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                printf("%d ", adjVertex);
                visited[adjVertex] = 1;
                enqueue(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }

    printf("\n");

    free(visited);
}
int isEmpty(struct Node* queue) {
    return (queue == NULL);
}


void enqueue(struct Node** queue, int vertex) {
    struct Node* newNode = createNode(vertex);
    if (*queue == NULL) {
        *queue = newNode;
    } else {
        struct Node* temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


int dequeue(struct Node** queue) {
    if (*queue == NULL) {
        return -1; 
    } else {
        struct Node* temp = *queue;
        int x = temp->vertex;
        *queue = (*queue)->next;
        free(temp);
        return x;
    }
}

int main() {
    int numVertices, choice, src, dest, startVertex;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    struct Graph* graph = createGraph(numVertices);

    do {
        printf("\n1. Add an edge to undirected graph");
        printf("\n2. Add an edge to directed graph");
        printf("\n3. Perform DFS traversal");
        printf("\n4. Perform BFS traversal");
        printf("\n5. Quit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices for undirected edge: ");
                scanf("%d %d", &src, &dest);
                addEdgeUndirected(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination vertices for directed edge: ");
                scanf("%d %d", &src, &dest);
                addEdgeDirected(graph, src, dest);
                break;
            case 3:
                printf("Enter the starting vertex for DFS traversal: ");
                scanf("%d", &startVertex);
                DFS(graph, startVertex);
                break;
            case 4:
                printf("Enter the starting vertex for BFS traversal: ");
                scanf("%d", &startVertex);
                BFS(graph, startVertex);
                break;
            case 5:
                printf("Quitting the program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
