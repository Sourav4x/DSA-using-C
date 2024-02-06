#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *lchild;
    struct node *rchild;
    int data;
}*root=NULL;

void insert(int key)
{
    struct node *p,*t,*r;
    t=root;
    if(root==NULL)
    {
        p=(struct node*)malloc(sizeof(struct node ));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;

    }
    else{
    while(t!=NULL)
    {
          r=t;
          if(key<t->data)
          {
            t=t->lchild;

          }
          else if(key>t->data)
          {
            t=t->rchild;
          }
          else{
            return;
          }
    }
    p=(struct node*)malloc(sizeof(struct node));
    p->lchild=NULL;
    p->rchild=NULL;
    p->data=key;
    if(p->data>r->data)
    {
        r->rchild=p;

    }
    else{
        r->lchild=p;
    }
    }

}
struct node *deltree(struct node *root)
{
    if(root!=NULL)
    {
        deltree(root->lchild);
        deltree(root->rchild);
        free(root);

    }
    return NULL;
}

void inorder(struct node *t)
{
    

    if(t!=NULL)
    {
        inorder(t->lchild);
        printf("%d\t",t->data);
        inorder(t->rchild);
        
    }
}
void preorder(struct node *t)
{
    if(t!=NULL)
    {
        printf("%d\t",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void postorder(struct node *t)
{
    if(t!=NULL)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d\t",t->data);
    }
}
int small(struct node *t)
{
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
    printf("%d is the smallest value",t->data);
}
int largest(struct node *t)
{
    while(t->rchild!=NULL)
    {
        t=t->rchild;
    }
    printf("%d is the largest value",t->data);
}
int search(struct node *t,int ele)
{
    if(t==NULL)
    {
        return 8;
    }
    if(t->data==ele)
    {
        return 4;
    }
    if(t->data > ele)
    {
       return search(t->lchild,ele);
    }
    return search(t->lchild,ele);
}
  int main()
{
    int choice,v,value,ele;
    do{
    printf("\nPress 1 to insert element in out bst");
    printf("\n Press 2 to display the whole in Inorder");
    printf("3. Pre-order Traversal\n");
    printf("4. Post-order Traversal\n");
    printf("5. Deletion of Tree\n");
    printf("6. Quit\n");
    printf("\n7. Search for smallest element \n");
    printf("\n8. find max element\n");
    printf("\n 9.search an element \n");
    printf("\nEnter ur choice:---  ");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:printf("\nenter the value u want to insrt:-- ");
        scanf("%d",&v);
        insert(v);
        break;
        case 2: printf("\n Inorder traversal of the tree is as follow's :___  ");
        inorder(root);
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
                root=deltree(root);
                printf("BST deleted.\n");
                break;

            case 6:
                printf("Exited \n");
                break;
             case 7:
             value=small(root);
             break;
             case 8:value=largest(root);
               break;
             case 9:printf("\n enter the element u want to search :-- ");
             scanf("%d",&ele);
             value=search(root,ele);
             if(value==4)
             {
                printf("\nit is present\n ");
             }
             else if(value==8){
                printf("not present \n");
             }
             break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 10);

    return 0;
}
