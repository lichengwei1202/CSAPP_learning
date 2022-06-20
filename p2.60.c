#include <stdio.h>
#include <string.h>
#include "show_bytes.h"
//见函数replace_byte
int main(void)
{
    //unsigned x = 0x12345678;
    //replace_byte(&x, 2, 0xab);
    //show_int(x);
    int x = 3;
    printf("%x",x<<3);
    return 0;
}