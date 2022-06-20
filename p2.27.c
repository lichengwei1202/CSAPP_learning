#include <stdio.h>
#include <string.h>

int uadd_ok(unsigned x, unsigned y); //判断两个无符号数相加是否发生溢出，如发生则返回0，未发生返回1.
int tadd_ok(int x, int y); //判断两个补码数相加是否发生溢出，如发生则返回0，未发生返回1.

int main(void)
{
    unsigned int a = 12;
    unsigned int b = 0xFFFFFFFE;
    int c = 0x80000000;
    int d = -1;
    printf("%d %x",tadd_ok(c,d), c+d);
    return 0;
}

int uadd_ok(unsigned x, unsigned y)
{
    unsigned result = x+y;

    if (result<x)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}

int tadd_ok(int x, int y)
{
    int result = x+y;

    int neg = x<0 && y<0 && result >0;
    int pos = x>0 && y>0 && result <0;

    return !neg && !pos;
}