#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *ptr,n,i;
    printf("enter the size of the array:-  ");
    scanf("%d",&n);
    ptr = calloc(n, sizeof(int));
    printf("\nenter array elements:-  ");


    for(i=1;i<n;i++)
    {
        scanf("%d\t",&ptr[i]);
    }
    findminmax(ptr,n);
    return 0;

}
int findminmax(int *d,int m)
{
    int i,j,p;
for(i=0;i<m;i++)
{
    for(j=i+1;j<m;j++)
    {
        if(*d[i]<*d[j])
    {
        p=*d[i];
        *d[i]=*d[j];
        *d[j]=p;
    }
    }
}
printf("\n The 2nd largest number is %d",*d[1]);
printf("\nThe 2nd smallest number is %d",*d[m-2]);
return 0;
}
