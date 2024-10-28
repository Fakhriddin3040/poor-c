#include <stdio.h>

int printChar(int);

int main(int argc, char const *argv[])
{
    printf("Enter target char: ");

    char input = getchar();

    unsigned char printCharRes = printChar(input);

    if(printCharRes != 0)
    {
        printf("Throwed unexpected exception!");
        return printCharRes;
    }

    printf("\n");
    //This code will get one char from user
    // and return himself and his code from ASCII char table.

    int putChar = 520;

    printf("The char, put by 'putchar()' method is: ");
    printChar(putChar);
    putchar(putChar);
    return 0;
}

int printChar(int putChar)
{
    printf("value: %c      ASCII code: %d",putChar, putChar);
    return 0;
}
