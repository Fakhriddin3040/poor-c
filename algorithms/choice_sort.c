#include <stdio.h>
#include <stdbool.h>


void choiceSort(int *arr, size_t size) {
    int min, tmp;

    for(int left = 0; left < size - 1; left++) {
        min = left;
        for(int right = left + 1; right < size; right++) {
            if(arr[right] < arr[min]) {
                min = right;
                }
            }
        if(arr[min] < arr[left]) {
            tmp = arr[left];
            arr[left] = arr[min];
            arr[min] = tmp;
        }
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {0, -21, 4, -1, 10, 5, 3, 10, 123};
    int *arr_ptr = arr;
    size_t arr_size = sizeof(arr) / sizeof(*arr);

    choiceSort(arr, arr_size);

    while(arr_ptr != arr + arr_size) {
        printf("%d\n", *arr_ptr);
        arr_ptr++;
    }
    printf("\n");
    return 0;
}