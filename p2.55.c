#include <stdio.h>
#include <string.h>
#include "show_bytes.h"
int main(void)
{
    int test = 0x12345678;
    long test_long = 0x12345612345612ef;
    short test_short = 0x1292;
    double test_double = (double)test;
    int a = 0x80;
    char *b = (char*) &a;
    //show_short(test_short);
    printf("%d", *b);
    return 0;
}
