#include <stdio.h>
#include <stdlib.h>
void addPolynomials(int A[], int B[], int m, int n)
 {
    int size;
    size=(m>n)?m:n;
    int *r = (int *)malloc((size + 1) * sizeof(int));


    for(int i=0;i<=size;i++)
    {
        r[i]=A[i]+B[i];
        if(i>m)
         r[i]=B[i];
        else if(i>n)
         r[i]=A[i];
    }

    printf("Resultant polynomial after addition: ");
    for (int i = size; i >= 0; i--) 
    {
        printf("%d", r[i]);
        if (i != 0) {
            printf("x^%d + ", i);
        }
    }
    printf("\n");

    free(r);
}

int main()
 {
    int m, n;

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

    addPolynomials(A, B, m, n);

    return 0;
}
