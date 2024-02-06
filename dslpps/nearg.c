#include <stdio.h>

void replaceWithNextGreatest(int arr[], int n) {
    int maxElement = arr[n - 1]; // Initialize maxElement with the last element
    
    // Iterate through the array in reverse order
    for (int i = n - 2; i >= 0; i--) {
        int currentElement = arr[i];
        arr[i] = maxElement; // Replace with the next greatest element
        if (currentElement > maxElement) {
            maxElement = currentElement; // Update maxElement if a greater element is encountered
        }
    }
}

int main() {
    int n;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[100]; // Assuming maximum array size is 100

    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    replaceWithNextGreatest(arr, n);
    
    printf("Array after replacing with next greatest elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    
    return 0;
}
