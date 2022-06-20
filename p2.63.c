#include "bytes_dance.h"
//见函数 unsigned srl(unsigned x, int k)
int main(void)
{
    int test = 0x21234567;
    unsigned result = sra(test,4);
    printf("%x",result);
    return 0;
}