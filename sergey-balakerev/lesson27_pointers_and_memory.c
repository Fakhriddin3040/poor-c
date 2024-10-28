#include <stdio.h>


int main()
{
    asm(
        "mov ax, 7"
        "add ax, 5"
    );

    return 0;
}
