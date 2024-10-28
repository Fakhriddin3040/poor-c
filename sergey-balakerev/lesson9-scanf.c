#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char var_ch;
    unsigned short var_sh;
    unsigned int var_i;
    float var_f;
    double var_d;

    scanf("%hhu %hu %u %f %lf", &var_ch, &var_sh, &var_i, &var_f, &var_d);

    printf(
        "Char: %d\n" 
        "Short: %hu\n"
        "Integer: %d\n"
        "Float: %f\n"
        "Double: %f\n",
        var_ch, var_sh, var_i, var_f, var_d
        );

    return 0;
}
