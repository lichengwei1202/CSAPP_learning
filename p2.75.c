#include "bytes_dance.h"
//见函数 xbyte函数
int main(void)
{
    int a = 114514;
    int b = 1919810;

    printf("%x\n%x", signed_high_prod(a,b), unsigned_high_prod(a,b));
}