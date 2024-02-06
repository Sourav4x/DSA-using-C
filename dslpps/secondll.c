#include<stdio.h>
void main()
{
    int a[10],i,ele,large,slt;
    printf("enter elemens in the array :-- ");
    for(i=0;i<7;i++)
    {
       scanf("%d\t",&a[i]);
    }
         ele=a[0];
         for(i=0;i<7;i++)
         {
            if(a[i]>ele)
            {
                ele=a[i];
            }
            large=ele;
            if(a[i]>ele && ele!=large)
            {
               ele=a[i];
            }
         }
         printf("\n%d is the largest element in the array and %d is the secoond largest element ",large,ele);
}