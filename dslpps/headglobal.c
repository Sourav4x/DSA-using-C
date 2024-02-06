#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int coef;
    int exp;
};

struct node *head = NULL;

struct node *create();
struct node *addnode(int coef, int exp);
void mul(struct node *head1, struct node *head2);
void display(struct node *head);

int main()
{
    struct node *head1, *head2;
    head1 = head2 = NULL;
    printf("\nEnter first polynomial: ");
    head1 = create();
    printf("\nEnter second polynomial: ");
    head2 = create();
    mul(head1, head2);
    return 0;
}

struct node *create()
{
    int n, i, coef, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter coeff in term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter exponent in term %d: ", i + 1);
        scanf("%d", &exp);
        head = addnode(coef, exp);
    }
    return head;
}

struct node *addnode(int coef, int exp)
{
    struct node *ptr;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = coef;
    newnode->exp = exp;
    newnode->next = NULL;
    ptr = head;
    if (head == NULL)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (ptr->next != NULL && ptr->next->exp >= exp)
        {
            ptr = ptr->next;
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    return head;
}

void mul(struct node *head1, struct node *head2)
{
    struct node *ptr1, *ptr2, *head3;
    ptr1 = head1;
    head3 = NULL;

    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while (ptr2 != NULL)
        {
            head3 = addnode(ptr1->coef * ptr2->coef, ptr1->exp + ptr2->exp);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    display(head3);
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;

    while (temp != NULL)
    {
        printf("(%dx^%d)", temp->coef, temp->exp);
        temp = temp->next;
        if (temp != NULL)
        {
            printf("+");
        }
    }
    printf("\n");
}
