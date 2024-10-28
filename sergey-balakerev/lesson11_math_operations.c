#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int time, seconds, minutes, hours, number, number2, result, result2;
    time = 14*3600 + 52*60 + 23;
    seconds = time % 60;
    minutes = (time / 60) % 60;
    hours = time / 3600; 

    printf(
        "Hours: %u\n"
        "Minutes: %u\n"
        "Seconds: %u\n",
        hours, minutes, seconds
        );

    number = 20;
    number2 = 20;
    result = 10 * ++number; // 210
    result2 = 10 * number2++; // 200

    printf(
        "Prefix increment: %d\n"
        "Postfix increment: %d\n",
        result, result2
    );

    return 0;
}
