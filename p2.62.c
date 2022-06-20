#include "bytes_dance.h"
//见函数replace_byte
int main(void)
{
    int test = 0x81234567;
    printf("%d",int_shift_are_arithmetic());
    printf("\n%x",test>>8);
    return 0;
}