#include <stdio.h>

int main(int argc, char const *argv[])
{
    char byte[10];
    int count;

    char* bytePointer = &byte[0];
    size_t byteStreamSize = sizeof(byte) - 1;

    printf("Enter a %zu length string: ", byteStreamSize);
    count = scanf("%s", bytePointer);

    for(size_t i = 0; i <= byteStreamSize; i++)
    {
        printf("%c", *bytePointer);
        bytePointer++;
    }

    printf("\n");

    printf(
        "Count of input: %d\n"
        "The first char is: %c\n"
        "The last char is: %c\n"
        "The pointer address is: %p",
        count, *byte, *bytePointer, bytePointer
        );

    return 0;
}