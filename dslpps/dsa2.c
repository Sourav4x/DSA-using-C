//22051031 q1
#include <stdio.h>
#include <stdlib.h>

void findMinMax(int arr[], int size)
 {
    int maxe = arr[0];
    int mine = arr[0];
    int maxp = 0;
    int minp = 0;

    for (int i = 1; i < size; ++i) 
    {
        if (arr[i] > maxe)
         {
            maxe = arr[i];
            maxp = i;
        }
        if (arr[i] < mine)
         {
            mine= arr[i];
            minp = i;
        }
    }

    printf("Max element= %d at position: %d\n", maxe, maxp);
    printf("Minimum Element= %d at position: %d\n", mine, minp);
}

int main()
 {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) 
    {
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

    findMinMax(arr, size);



    return 0;
}
