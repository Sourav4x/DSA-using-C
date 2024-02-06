#include<stdio.h>
#include<stdlib.h>
int parition(int a[],int l,int h)
{
    int pivot=l;
    int i,j;
    i=l;
    j=h;
    do{
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j] > pivot);
    }while(i<j);
    swap(&a[i],&a[j]);
    return j;
}

swap(int *x,int *y)
{
    int *z;
    *z=*x;
    *x=*y;
    *y=*z;

}
void print(int a[],int n)
{
    int i;
   for(i=0;i<n;i++)
   {
    printf("%d\t",a[i]);
   }
}
 void random(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand ()%100 +1;
    }
}
void insertionsort(int a[],int n)
{
    int i,j,x;
    for(i=1;i<n;i++)
    {
        j=i-1;
          x=a[i];
          if(a[j]>x && j>-1)
          {
            a[j+1]=a[j];
          }
          a[j+1]=x;
    }
}

void bubblesort(int a[],int n)
{
  int i,j;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
        if(a[j] > a[j+1])
        {
          swap(&a[j],&a[j+1]);
        }
    }
  }
}

void selectionsort(int a[],int n)
{
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
       for(j=k=i;j<n;j++)
       {
        if(a[k]>a[j])
        {
            k=j;
        }
       }
       swap(&a[i],&a[k]);
    }
}
void main()
{
    int *arr,i,n;
    printf("enter the no of elements :-- ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    random(arr,n);
    bubblesort(arr,n);
    printf("\nAFTER BUBBLE SORT:--  ");
    print(arr,n);
    random(arr,n);
    insertionsort(arr,n);
    printf("\nAFTER insertion  SORT:--  ");
    print(arr,n);

}