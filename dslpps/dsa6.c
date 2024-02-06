
//22051031 Q2 solution
#include <stdio.h>
#include <stdlib.h>

void findSecondMinMax(int *arr, int size) 
{
    int max1 = arr[0], max2 = arr[0];
    int min1 = arr[0], min2 = arr[0];
    int posm = 0, posm2 = 0;
    int posmin = 0, posmin2 = 0;

    for (int i = 0; i < size; i++) 
    {
        if (arr[i] > max1) 
        {
            max2 = max1;
            posm2 = posm;
             max1 = arr[i];
            posm = i;
        } else if (arr[i] > max2 && arr[i] != max1) 
        {
            max2 = arr[i];
            posm2 = i;
        }

        if (arr[i] < min1) 
        {
            min2 = min1;
            posmin2 = posmin;

            min1 = arr[i];
            posmin = i;
        }
         else if (arr[i] < min2 && arr[i] != min1) 
        {
            min2 = arr[i];
            posmin2 = i;
        }
    }

    printf("Second Maximum: %d at position %d\n", max2, posm2);
    printf("Second Minimum: %d at position %d\n", min2, posmin2);
}

int main()
 {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *)calloc(size,sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }

    findSecondMinMax(arr, size);

    free(arr);
    return 0;
}
