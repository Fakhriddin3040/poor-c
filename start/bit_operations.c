#include <stdio.h>

int main(void)
{
    int a[] = {1, 2, 3, 4, 5};


    for(size_t i = 0; i < sizeof(a) / 4; i++)
    {
        void *p_a = &a;
        printf("%d\n", *(int *)(p_a + i * 4));  
    }

    return 0;
}
