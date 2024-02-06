
#include<stdio.h>
#include<math.h>
struct CompNo
{
    int r;
    int i;
};
void operations(struct CompNo c1,struct CompNo c2)
{
   int n;
   int a=c1.r,b=c2.r,c=c1.i,d=c2.i;
   printf("Press 1 for addition\nPress 2 for subtraction\nPress 3 for multiplication\nPress 4 for division");
   scanf("%d",&n);
   int e,f,g,h,i,j;
   float k,l;
   e=a+b;
   f=c+d;
   g=a-b;
   h=c-d;
   i=(a*b)-(c*d);
   j=(a*d)+(b*c);
   k=(a*c+b*d)/(pow(c,2)+pow(d,2));
   l=(b*c-a*d)/(pow(c,2)+pow(d,2));
   switch(n)
   {
        case 1:
        printf("%d+%di",e,f);
        break;
        case 2:
        printf("%d+%di",g,h);
        break;
        case 3:
        printf("%d+%di",i,j);
        break;
        case 4:
        printf("%d+%di",k,l);
   }
}
int main()
{
    struct CompNo Q1;
    struct CompNo Q2;
    printf("Enter Complex No 1:\n");
    printf("Real Part:\t");
    scanf("%d",&Q1.r);
    printf("Complex Part:\t");
    scanf("%d",&Q1.i);
    printf("Enter Complex No 2:\n");
    printf("Real Part:\t");
    scanf("%d",&Q2.r);
    printf("Complex Part:\t");
    scanf("%d",&Q2.i);
    operations(Q1,Q2);
    return 0;
}