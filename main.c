#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j + 1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, MinIDX, temp;
    for (i = 0; i < n - 1; i++) {
        MinIDX = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[MinIDX])
                MinIDX = j;
        }
        temp = arr[MinIDX];
        arr[MinIDX] = arr[i];
        arr[i] = temp;
        swaps[arr[MinIDX]]++;
        swaps[arr[i]]++;
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[101] = {0};
    int swaps2[101] = {0};

    bubbleSort(array1, n1, swaps1);
    
    printf("Array 1:\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d swapped\n", array1[i], swaps1[array1[i]]);
    }

    selectionSort(array2, n2, swaps2);

    printf("\nArray 2:\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d swapped\n", array2[i], swaps2[array2[i]]);
    }

    int totalSwaps1 = 0, totalSwaps2 = 0;
    for (int i = 0; i < 101; i++) {
        totalSwaps1 += swaps1[i];
        totalSwaps2 += swaps2[i];
    }
    
    printf("\nTotal number of swaps for Array 1: %d\n", totalSwaps1);
    printf("Total Number of swaps for Array 2: %d\n", totalSwaps2);

    return 0;
}
