#include <stdio.h>

void insertSort(int arr[], int len)
{
    int key, i;
    for (int j = 1; j < len; ++j) {
        key = arr[j];
        // Insert arr[i] into the sorted sequence
        // arr[1..j - 1]
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        printf("%i ", arr[i]);

    printf("\n");
}

int main() {
    int arr[6] = {31, 41, 59, 26, 41, 58};

    printArr(arr, 6);
    insertSort(arr, 6);
    printArr(arr, 6);

    return 0;
}
