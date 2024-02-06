#include <stdio.h>

void printElementsBelowMinorDiagonal(int arr[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j) {
                printf("%d ", arr[i][j]);
            }
        }
    }
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int arr[100][100]; // Assuming maximum size of the array is 100x100
    
    printf("Enter the elements of the 2-D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    printf("Elements below the minor diagonal:\n");
    printElementsBelowMinorDiagonal(arr, rows, cols);
    
    return 0;
}
