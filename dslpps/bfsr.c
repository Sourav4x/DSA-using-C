#include <stdio.h>
#include <stdlib.h>

#define n 10

struct node {
    int data;
    struct node *next;
};

int adj[n][n];
int vist[n];

// Function prototypes
void creategraph(int graphtype, int maxedge, int (*a)[2]);
void recursivedfs(int vertex);
void bfs(int startVertex);

int main() {
    int a[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {-1, -1}};
    int t, maxedge, graphtype;

    printf("Enter 1 for an undirected graph & 2 for a directed graph: ");
    scanf("%d", &graphtype);

    if (graphtype == 1) {
        maxedge = n * (n - 1) / 2;
    } else {
        maxedge = n * (n - 1);
    }

    creategraph(graphtype, maxedge, a);

    printf("Enter the starting vertex: ");
    scanf("%d", &t);

    printf("DFS Traversal starting from vertex %d: ", t);
    recursivedfs(t);
    printf("\n");

    printf("BFS traversal starting from vertex %d: ", t);
    bfs(t);
    printf("\n");

    return 0;
}

void creategraph(int graphtype, int maxedge, int (*a)[2]) {
    int i, origin, destin;

    for (i = 0; i < n; ++i) {
        vist[i] = 0;
    }

    for (i = 0; i < maxedge; ++i) {
        origin = a[i][0];
        destin = a[i][1];

        if ((origin == -1) && (destin == -1)) {
            break;
        } else {
            adj[origin][destin] = 1;
            if (graphtype == 1) {
                adj[destin][origin] = 1;
            }
        }
    }
}

void recursivedfs(int vertex) {
    int i;
    vist[vertex] = 1;

    printf("%d ", vertex);

    for (i = 0; i < n; ++i) {
        if (adj[vertex][i] == 1 && vist[i] == 0) {
            recursivedfs(i);
        }
    }
}

void bfs(int startVertex) {
    int u, i;
    struct node *front = NULL;
    struct node *rear = NULL;

    void enqueue(int v) {
        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = v;
        ptr->next = NULL;
        if (rear == NULL && front == NULL) {
            rear = front = ptr;
        } else {
            rear->next = ptr;
            rear = ptr;
        }
    }

    int dequeue() {
        if (front == NULL) {
            printf("\nUnderflow\n");
            return -1;
        } else {
            struct node *ptr = front;
            int x = ptr->data;
            front = front->next;
            free(ptr);
            return x;
        }
    }

    int empty() {
        return (front == NULL && rear == NULL);
    }

    printf("%d ", startVertex);
    vist[startVertex] = 1;
    enqueue(startVertex);

    while (!empty()) {
        u = dequeue();
        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1 && vist[i] == 0) {
                printf("%d ", i);
                vist[i] = 1;
                enqueue(i);
            }
        }
    }

    // Clean up: Free allocated memory for the nodes
    while (!empty()) {
        dequeue();
    }
}
