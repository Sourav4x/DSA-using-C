 #include<stdio.h>
 #include<stdlib.h>
 void random(int a[],int n )
 {
    int i;
    for(i=0;i<n;i++)
    {
        a[i]=rand () % 100 +1;
    }
 }
 void swap(int *x,int *y)
{
    int *z;
    *z=*x;
    *x=*y;
    *y=*z;

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
 int main()
 {
    int *arr,k,i;
    arr=(int*)malloc(10*sizeof(int));
    random(arr,10);
    bubblesort(arr,10);
    printf("\nenter the kth element :-- ");
    scanf("%d",&k);

    printf("the array now becomes after sorting is applied -- ");
    for(i=0;i<10;i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n the value of Kth largest element is %d",arr[(10-k)]);
    return 0;


 }