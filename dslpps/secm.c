#include <stdio.h>
#include <stdlib.h>

void findSecondMinMax(int *array, int size) {
  int i, max, sec_max, min, sec_min, position;

  // Initialize max, sec_max, min, and sec_min as the first element of the array.
  max = sec_max = array[0];
  min = sec_min = array[0];

  // Loop through the rest of the array.
  for (i = 1; i < size; i++) {
    // If the current element is greater than max, then update max and sec_max.
    if (array[i] > max) {
      sec_max = max;
      max = array[i];
    } else if (array[i] > sec_max) {
      sec_max = array[i];
    }

    // If the current element is less than min, then update min and sec_min.
    if (array[i] < min) {
      sec_min = min;
      min = array[i];
    } else if (array[i] < sec_min) {
      sec_min = array[i];
    }
  }

  // Print the second maximum and second minimum element along with their positions.
  printf("The second maximum element is %d\t at position %d\n", sec_max, position = (sec_max == array[0]) ? 1 : 0);
  printf("The second minimum element is %d\t at position %d\n", sec_min, position = (sec_min == array[0]) ? 1 : 0);
}

int main() {
  int *array, size;

  // Get the size of the array.
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Allocate memory for the array.
  array = (int *)malloc(sizeof(int) * size);

  // Initialize the array elements.
  for (int i = 0; i < size; i++) {
    printf("Enter the element at index %d: ", i);
    scanf("%d", &array[i]);
  }

  // Find the second maximum and second minimum element from the array.
  findSecondMinMax(array, size);

  // Free the memory allocated for the array.
  free(array);

  return 0;
}