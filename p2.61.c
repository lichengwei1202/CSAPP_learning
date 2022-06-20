#include <stdio.h>
#include <string.h>
#include "bytes_dance.h"
//见函数replace_byte
int main(void)
{
    int test = 0x00123fff;
    
    printf("%d", is_high_zero(test));

    return 0;
}
