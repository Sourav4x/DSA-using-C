#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *lchild;
    struct node *rchild;
    int data;
} *root = NULL;

void insert(int key) {
    struct node *p, *t, *r;
    t = root;

    if (root == NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
    } else {
        while (t != NULL) {
            r = t;
            if (key < t->data) {
                t = t->lchild;
            } else if (key > t->data) {
                t = t->rchild;
            } else {
            
                t->data = key;
                return;
            }
        }

    
        p = (struct node *)malloc(sizeof(struct node));
        p->lchild = p->rchild = NULL;
        p->data = key;

        if (p->data > r->data) {
            r->rchild = p;
        } else {
            r->lchild = p;
        }
    }
}

struct node *deltree(struct node *root) {
    if (root != NULL) {
        deltree(root->lchild);
        deltree(root->rchild);
        free(root);
    }
    return NULL;
}

void inorder(struct node *t) {
    if (t != NULL) {
        inorder(t->lchild);
        printf("%d\t", t->data);
        inorder(t->rchild);
    }
}

void preorder(struct node *t) {
    if (t != NULL) {
        printf("%d\t", t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void postorder(struct node *t) {
    if (t != NULL) {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\t", t->data);
    }
}

int small(struct node *t) {
    while (t->lchild != NULL) {
        t = t->lchild;
    }
    printf("%d is the smallest value", t->data);
}

int largest(struct node *t) {
    while (t->rchild != NULL) {
        t = t->rchild;
    }
    printf("%d is the largest value", t->data);
}

int search(struct node *t, int ele) {
    if (t == NULL) {
        return 8;
    }
    if (t->data == ele) {
        return 4;
    }
    if (t->data > ele) {
        return search(t->lchild, ele);
    }
    return search(t->rchild, ele);
}

int main() {
    int choice, v, ele;

    do {
        printf("\nPress 1 to insert element in the BST");
        printf("\nPress 2 to display the tree in Inorder");
        printf("\nPress 3 for Pre-order Traversal");
        printf("\nPress 4 for Post-order Traversal");
        printf("\nPress 5 for Deletion of Tree");
        printf("\nPress 6 to Quit");
        printf("\nPress 7 to Search for the smallest element");
        printf("\nPress 8 to find the largest element");
        printf("\nPress 9 to search for an element");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value you want to insert: ");
                scanf("%d", &v);
                insert(v);
                break;

            case 2:
                printf("\nInorder traversal of the tree: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                root = deltree(root);
                printf("BST deleted.\n");
                break;

            case 6:
                printf("Exiting.\n");
                break;

            case 7:
                small(root);
                break;

            case 8:
                largest(root);
                break;

            case 9:
                printf("\nEnter the element you want to search: ");
                scanf("%d", &ele);
                int value = search(root, ele);
                if (value == 4) {
                    printf("\nElement is present.\n");
                } else if (value == 8) {
                    printf("Element is not present.\n");
                }
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
