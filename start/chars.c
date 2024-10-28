#include <stdio.h>
#include <stdbool.h>


int main()
{
    char name[6] = "World!";
    char *ptr = &name;

    printf("The name is: ");

    size_t count = 0;

    while (count < sizeof(name))
    {
        printf("%c", *ptr);
        ptr += 1, count++;
    }

    return 0;
}
