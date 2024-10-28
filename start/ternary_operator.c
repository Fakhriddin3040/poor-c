#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int a = 10;
    int b = 23;

    int *a_p = &a;
    int *b_p = &b;

    long long pointer_diff = a_p - b_p;

    printf("Difference between %p - %p is: %lld \n", (void *)a_p, (void *)b_p, -pointer_diff);

    return 0;
}