#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n;
    printf("Polynomial 1:");
    printf("Enter the highest order of the polynomial");
    scanf("%d",&m);
    printf("Polynomial 2:");
    printf("Enter the highest order of the polynomial");
    scanf("%d",&n);
    int a[m],b[n];
    printf("Polynomial 1:");
    printf("Enter the coefficients");
    for(int i=0;i<=m;i++)
        scanf("%d",&a[i]);
    printf("Polynomial 2:");
    printf("Enter the coefficients");
    for(int i=0;i<=n;i++)
        scanf("%d",&b[i]);
    int *c;
    c=(int*)calloc(m+n+1,sizeof(int));
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            c[i+j]=c[i+j]+a[i]*b[j];
    }
    for(int i=0;i<=(m+n);i++)
        printf("%d\t",c[i]);
    return 0;
}