#include "bytes_dance.h"
//见函数 xbyte函数
int main(void)
{
    packed_t test = 0x12345678;

    printf("%d", xbyte(test,0));
}