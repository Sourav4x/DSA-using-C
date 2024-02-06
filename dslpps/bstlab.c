/*22051031 DS LAB ACTIVITY*/
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
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
 void smallest(struct node *t)
 {
    t=root;
    while(t->lchild!=NULL)
    {
        t=t->lchild;
    }
    printf("\n%d is the smallest element present \n",t->data);
 }

 void largest(struct node *t)
 {
    t=root;
    while(t->rchild!=NULL)
    {
        t=t->rchild;
    }
    printf("\n %d is the largest element present\n",t->data);
 }
int height(struct node *t)
{
 int x=0,y=0;
 if(t==0)
 return 0;
 x=height(t->lchild);
 y=height(t->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;
 
} 


 int main()
 {
    int x;
    insert(8);
    insert(3);
    insert(10);
    insert(1);
    insert(6);
    insert(14);
    insert(4);
    insert(7);
    insert(12);
    printf("\n");
    smallest(root);
    printf("\n");
    largest(root);
    printf("\n");
    printf("%d is the height",height(root));
 }
