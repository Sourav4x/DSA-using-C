#include<stdio.h>
#include<stdlib.h>
void main()
{
    int *a,i,n;
    printf("Enter the no of elements of the array:--");
    scanf("%d",&n);
    a=(int*)calloc(n,sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    int m=0;
    int c=n-1;
    printf("the reversed array is:--");
    for(i=0;i<n/2;i++)
    {
        m=a[i];
        a[i]=a[c];
        a[c]=m;
        c--;
    }
    printf("The reversed array is :--- ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }


}