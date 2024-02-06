#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
}

void random(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;
    }
}

void insertionsort(int a[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        j = i - 1;
        x = a[i];
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = x;
    }
}

void bubblesort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int partition(int a[], int l, int h) {
    int pivot = a[l];
    int i = l;
    int j = h;

    while (1) {
        while (i <= j && a[i] <= pivot) {
            i++;
        }

        while (i <= j && a[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(&a[i], &a[j]);
        } else {
            break;
        }
    }

    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int h) {
    if (l < h) {
        int p = partition(a, l, h);
        quicksort(a, l, p);
        quicksort(a, p + 1, h);
    }
}

void merge(int a[], int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int l, int h) {
    if (l < h) {
        int m = l + (h - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

int main() {
    int *arr, i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));


    random(arr, n);
    bubblesort(arr, n);
    printf("\nAfter Bubble Sort: ");
    print(arr, n);

    
    random(arr, n);
    insertionsort(arr, n);
    printf("\nAfter Insertion Sort: ");
    print(arr, n);

    
    random(arr, n);
    quicksort(arr, 0, n - 1);
    printf("\nAfter Quick Sort: ");
    print(arr, n);

    
    random(arr, n);
    mergesort(arr, 0, n - 1);
    printf("\nAfter Merge Sort: ");
    print(arr, n);

    free(arr);
    return 0;
}
