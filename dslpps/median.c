#include <stdio.h>

float find_median(int array[], int n) {
  int i, j;
  float median;

  if (n % 2 == 0) {
    median = (array[n / 2] + array[(n-1)/2]) / 2;
  } else {
    median = array[n / 2];
  }

  return median;
}

int main() {
    float median;
  int array[] = {1,3,4,2,6,5,8,7};
  int n = sizeof(array) / sizeof(array[0]);

  median = find_median(array, n);

  printf("The median is: %f\n", median);

  return 0;
}
