#include "bytes_dance.h"
//见函数 bool any_odd_one(unsigned x)
int main(void)
{
    unsigned x = 0x10000001;
    printf("%x\n",x>>1);
    x = x^(x>>1);
    printf("%x\n",x);
    x = x^(x>>2);
    printf("%x\n",x);
    x = x^(x>>4);
    printf("%x\n",x);
    x = x^(x>>8);
    printf("%x\n",x);
    x = x^(x>>16);
    printf("%x",x);
}