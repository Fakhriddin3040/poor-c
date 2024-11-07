#include <stdio.h>
#include <stdlib.h>

int divide_field(int value1, int value2) {
    if(value2 == 0) {
        return value1;
    }
    return divide_field(value1, value2 % value1);
}


int main(void) {
    int res = divide_field(1680, 640);
    printf("%d", 15 % 150);
    return 0;
}
