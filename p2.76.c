#include "bytes_dance.h"
//见函数 xbyte函数
int main(void)
{
    int a = 1;
    int b = 4;
    
    printf("%lu",sizeof(*(int *)calloc_simulate(a,b)));
}