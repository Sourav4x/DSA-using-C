#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *a,*b,n,m;
    printf("Enter the size of the array 1:- ");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    printf("Enter the size of array 2:- ");
    scanf("%d",&m);
    b=(int*)malloc(m*sizeof(int));
    for(int i=0;i<m;i++)
    {
        scanf("%d",(b+i));
    }
    for(int i=0;i<m;i++)
    {
        a[n+i]=b[i];
    }
    int k=m+n;
    printf("The merged array:--");
    for(int i=0;i<k;i++)
    {
        printf("%d\t",*(a+i));
    }
    
}