#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

int* bin_search(int *arr, int target, int size) {
    int *mid = malloc(sizeof(int));
    int cur, left = 0, right = size - 1;

    while(left <= *mid) {
        *mid = (right + left) / 2;
        cur = arr[*mid];

        if(cur == target) {
            return mid;
        }
        else if(cur < target) {
            left = *mid + 1;
        }
        else {
            right = *mid - 1;
        }
    }
    return NULL;
}


int arr[ARR_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 25}; 


int main(void) {
    int target_value = 25;
    int *res_ptr = bin_search(arr, target_value, ARR_SIZE);

    if(res_ptr == NULL) {
        fprintf(stderr, "Target value not found.");
        exit(EXIT_FAILURE);
    }
    printf("Target value index: %d", *res_ptr);
    free(res_ptr);
    return 0;
}