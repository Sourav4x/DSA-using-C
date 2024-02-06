#include <stdio.h>

int binarySearch(int arr[], int n, int item) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == item) {
      return mid;
    } else if (arr[mid] < item) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

int main() {
  int n, item;

  
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  
  int arr[n];

  

  
  printf("Enter the elements of the sorted array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  
  printf("Enter the item to search for: ");
  scanf("%d", &item);

  
  int index = binarySearch(arr, n, item);

  
  if (index == -1) {
    printf("Item %d not found.\n", item);
  } else {
    printf("Item %d found at index %d.\n", item, index);
  }

  return 0;
}
