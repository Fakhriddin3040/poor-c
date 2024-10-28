#include <stdio.h>


int main(int argc, char const *argv[])
{
    int dec, hex, oct, bin;
    dec = 100;
    hex = 0x64; // 0x is a prefix for hexadecimal numbers.
    oct = 0144; // 0 is a prefix for octal numbers.
    bin = 0b1100100; // 0b is a prefix for binary numbers.
    printf("Decimal: %d\n", dec);
    printf("Hexadecimal: %d\n", hex);
    printf("Octal: %d\n", oct);
    size_t size = sizeof(bin);
    printf("Binary: %d, Size: %zu\n", bin, size);
    return 0;
}
