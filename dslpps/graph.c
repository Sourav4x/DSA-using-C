#include<stdio.h>
#include<stdlib.h>
#define n 10
int adj[n][n];
int x;
int vist[n];

int main()
{
    int a[][2]={{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,7},{5,7},{6,7},{-1,-1}};
    int i,maxedge,graphtype,startvertex;
    x=8;
    printf("\n  Enter 1 for undirected graph & 2 for  directed graph :-- ");
    scanf("%d",&graphtype);
    if(graphtype==1)
    {
        maxedge=(n)*(n-1)/2;
    }
    else{
        maxedge=(n)*(n-1);
    }
    creategraph(graphtype,maxedge,a);
    recursivedfs(0);
}
void creategraph(int graphtype,int maxedge,int (*a)[2])
{
    int i,origin,destin;
    for(i=0;i<maxedge;++i)
    {
        origin=a[i][0];
        destin=a[i][1];
    
    if((origin==-1) && (destin==-1))
    {
        break;
    }
    else{
           adj[origin][destin]=1;
           if(graphtype==1)
           {
            adj[destin][origin]=1;
           }
    }
    }
    }
    void recursivedfs(int u)
    {
        int i;
    if(vist[u]==0)
    {
        printf("%d\n",u);
        vist[u]=1;
        for(i=0;i<n;++i)
        {
            if(adj[u][i]==1 && vist[i]==0)
            {
                recursivedfs(i);
            }
        }
    }
        
    }
