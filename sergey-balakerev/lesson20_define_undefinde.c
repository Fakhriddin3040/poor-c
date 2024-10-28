#include <stdio.h>

#define PRINTUSERATTRIBUTE(ATTR) user ## ATTR


int main(int argc, char const *argv[])
{
    char* username = "John";
    printf("Username: %s\n", PRINTUSERATTRIBUTE(name));
    return 0;
}
