#include <stdio.h>

int main() {
  int n, item;


  printf("Enter the size of the array: ");
  scanf("%d", &n);

  
  int arr[n];

  
  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }


  printf("Enter the item to search for: ");
  scanf("%d", &item);


  int index = linearSearch(arr, n, item);

  
  if (index == -1) {
    printf("Item %d not found.\n", item);
  } else {
    printf("Item %d found at index %d.\n", item, index);
  }

  return 0;
}


int linearSearch(int arr[], int n, int item) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == item) {
      return i;
    }
  }
  return -1;
}
