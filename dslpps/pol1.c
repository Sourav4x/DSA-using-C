#include<stdio.h>
void poly(int a[],int b[],int d,int c)
{
    int s[100],size;
    if(d>c)
    {
      size=d;
    }
    else if(c>d)
    {
          size=c;
    }
     
     for(int i=0;i<=size;i++)
     {
        s[i]=a[i]-b[i];
     }
     printf("Resultant polynomial after addition: ");
    for (int i = size; i >= 0; i--) 
    {
        printf("%d", s[i]);
        if (i != 0)
         {
            printf("x^%d + ", i);
        }
    }
    printf("\n");
}
int main()
 {
    int m,n;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &m);

    int A[m + 1];
    printf("Enter the coefficients of the first polynomial:\n");
    for (int i = m; i >= 0; i--)
     {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &A[i]);
    }

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &n);

    int B[n + 1];
    printf("Enter the coefficients of the second polynomial:\n");
    for (int i = n; i >= 0; i--)
     {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &B[i]);
    }

    poly(A, B, m,n);

    return 0;
 }