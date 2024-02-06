#include <stdio.h>
#include <stdlib.h>

#define n 10

int adj[n][n];
int x;
int vist[n];
struct node{
    int data;
    struct node *next;
};
void creategraph(int graphtype, int maxedge, int (*a)[2]);
void recursivedfs(int vertex);
void bfs(int vertex);

int main() {
    int a[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {-1, -1}};
    int i, t, maxedge, graphtype, startvertex;
    x = 8;

    printf("\nEnter 1 for an undirected graph & 2 for a directed graph: ");
    scanf("%d", &graphtype);

    if (graphtype == 1) {
        maxedge = (n) * (n - 1) / 2;
    } else {
        maxedge = (n) * (n - 1);
    }

    creategraph(graphtype, maxedge, a);

    printf("\nEnter the starting vertex: ");
    scanf("%d", &t);

    printf("\nDFS Traversal starting from vertex %d: ", t);
    recursivedfs(t);
    printf("\n");

    printf("\nBFS traversal starting from vertex %d: ", t);
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

void bfs(int svertex) {
    int u, i;
    struct node *front = NULL;
    struct node *rear = NULL;

    void enqueue(int v)
    {
      struct node *ptr;
      
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = v;
        ptr->next = NULL;
        if ((rear == NULL) && (front == NULL)) {
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
        if ((rear == NULL) && (front == NULL)) {
            return 1;
        } else {
            return 0;
        }
    }

    printf("%d ", svertex);
    vist[svertex] = 1;
    enqueue(svertex);

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
}
