#include<stdio.h>
#include<stdlib.h>
#define num 4
 typedef struct node{
    int vertex;
    struct node *next;
 }node;

 typedef struct list {
    struct node *head;
    
 }list;

 list *adj[num];


 void addnode(int s,int d)
 {
    int i;
    node *src,*dst,*tmp;
       if(adj[s]->head==NULL)
       {
        src=(node*)malloc(sizeof(node));
        src->vertex=s;
        src->next=NULL;
        adj[s]->head=src;
       }
       dst=(node*)malloc(sizeof(node));
       dst->vertex=d;
       dst->next=NULL;
       tmp=adj[s]->head;
       while(tmp->next!=NULL)
       {
        tmp=tmp->next;
       }
        tmp->next=dst;
       
 }
 void printlist()
 {
    node *p,*q;
    int i;
    for(i=1;i<num;i++)
    {
        p=adj[i]->head;
        while(p)
        {
            printf("%d\t",p->vertex);
            p=p->next;
        }
        printf("\n");
    }
 }
    
 
 void main()
 {
    int i;
    for(i=0;i<num;i++)
    {
       adj[i]=(list*)malloc(sizeof(list));
       adj[i]->head=NULL;
    }
    addnode(0,1);
    addnode(0,2);
    addnode(1,3);
    addnode(2,3);
    addnode(2,4);
printlist();
 }

