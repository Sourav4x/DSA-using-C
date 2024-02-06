#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;  // Not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;  // Not prime
        }
    }
    return 1;  // Prime
}

int main() {
    int arr[] = { 2, 3, 5, 6, 7, 11, 15, 17, 19, 21 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int iterationCount = 0;
    
    printf("Odd prime elements in the array:\n");
    for (int i = 0; i < n; i++) {
        iterationCount++; // Counting iterations
        
        if (arr[i] % 2 != 0 && isPrime(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\nNumber of iterations: %d\n", iterationCount);

    return 0;
}
