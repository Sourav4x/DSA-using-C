#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *a,n;
    printf("enter the size :---  ");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    int temp=0;
    int d=n/2;
    for(int i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[d];
        a[d]=temp;
        d++;



    }
    printf("\nthe array after rotation:--- \n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(a+i));
    }

}