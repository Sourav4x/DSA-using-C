#include <stdio.h>

int binarySearch(int arr[], int low, int high, int item) {
  if (low > high) {
    return -1;
  }

  int mid = (low + high) / 2;

  if (arr[mid] == item) {
    return mid;
  } else if (arr[mid] < item) {
    return binarySearch(arr, mid + 1, high, item);
  } else {
    return binarySearch(arr, low, mid - 1, item);
  }
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

  
  int index = binarySearch(arr, 0, n - 1, item);


  if (index == -1) {
    printf("Item %d not found.\n", item);
  } else {
    printf("Item %d found at index %d.\n", item, index);
  }

  return 0;
}
