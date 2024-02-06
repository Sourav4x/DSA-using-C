#include <stdio.h>
#include <stdlib.h>

void findMinMax(int arr[], int size) {
    int maxe= arr[0];
    int mine=arr[0];
    int arr[0];
    int maxPosition = 0;
    int minPosition = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxe) {
            maxe = arr[i];
            maxPosition = i;
        }
        if (arr[i] < mine) {
            mine = arr[i];
            minPosition = i;
        }
    }

    printf("Maximum Element: %d at position: %d\n", maxe, maxPosition);
    printf("Minimum Element: %d at position: %d\n", mine, minPosition);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *ar = (int *)malloc(size * sizeof(int));

    if (ar == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &ar[i]);
    }

    findMinMax(ar, size);

    
    return 0;
}
