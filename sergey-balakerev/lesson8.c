#include <stdio.h>

int main(int argc, char const *argv[])
{
    int integer = 150;
    double dbl = 15.516F;
    float flt = 15.516F;
    printf("Float: [%+.21f]\n", dbl);
    printf("Integer: [%#X]", integer);
    return 0;
}
