#include<stdio.h>
#include<stdlib.h>
void findsecMinMax(int arr[], int size) 
{
    int small1,small2;
    small1=small2=arr[0];
    int max1,max2;
    max1=max2=arr[0];
    int minp = 0;
    int maxp=0;

    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] < small1) 
        {
            small2 = small1;
            small1 = arr[i];
        }
        else if(arr[i] < small2)
        {
            small2=arr[i];
            minp=i;
        }
    
    }

        printf("\nthe 2nd smallest element is %d and pos is %d",small2,minp);
    
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL) 
    {
        printf("Memory alloc failed\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; ++i)
     {
        scanf("%d", &arr[i]);
    }

    findsecMinMax(arr, size);



    return 0;
}

