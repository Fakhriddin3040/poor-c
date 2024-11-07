#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int arr[ARR_SIZE] = {-1, -6, 1, 3, 356, 7, 22, 14, 976, 24};


int choose_sort(int *arr, size_t size) {
    int tmp, min = 0;

    for(size_t left = 0; left < size - 1; left++) {
        min = left;

        for(size_t right = left + 1; right < size; right++) {

            if(arr[right] < arr[min]) {
                min = right;
            }
        }
        if(arr[min] != arr[left]) {
            tmp = arr[left];
            arr[left] = arr[min];
            arr[min] = tmp;
        }
    }
    return 0;
}
