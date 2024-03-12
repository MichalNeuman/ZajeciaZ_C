#include <stdio.h>

int binarySearchRecursive(int *arr, int left, int right, int value) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        
        if (arr[mid] == value)
            return mid;

        
        if (arr[mid] > value)
            return binarySearchRecursive(arr, left, mid - 1, value);

        
        return binarySearchRecursive(arr, mid + 1, right, value);
    }

    
    return -1;
}

int main() {
    int arr[] = {11, 12, 22, 25, 34, 64, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 22;

    int result = binarySearchRecursive(arr, 0, size - 1, value);

    if (result != -1)
        printf("Element %d znajduje się na indeksie %d.\n", value, result);
    else
        printf("Element %d nie został znaleziony w tablicy.\n", value);

    return 0;
}
