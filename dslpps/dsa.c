#include <stdio.h>
#include <stdlib.h>

void findMinMax(int arr[], int n) {
    int maxElement = arr[0];
    int minElement = arr[0];
    int maxPosition = 0;
    int minPosition = 0;
    int n;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
            maxPosition = i;
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
            minPosition = i;
        }
    }

    printf("Maximum Element: %d at position: %d\n", maxElement, maxPosition);
    printf("Minimum Element: %d at position: %d\n", minElement, minPosition);
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }


    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, n);

    

    return 0;
}
