#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[10];
    char gender;
    char desig[3];
    int Pay;

}employee;
int grosspay(int s){
    return(s+0.25*s+0.5*s);
}
void main()
{
    int n;
    printf("enter the no of employees");
    scanf("%d",&n);
    employee a=(employee)malloc(n*sizeof(employee));
    for(int i=0;i<n;i++)
    {
        printf("no %d employee details\n",i+1);
        scanf("%s %s %s %d",a[i].name,&a[i].gender,a[i].desig,&a[i].Pay);
    }
    for(int i=0;i<n;i++)
    {
        float g=grosspay(a[i].Pay);
        printf("GROSS SALARY OF %s IS %f\n",a[i].name,g);

    }
}