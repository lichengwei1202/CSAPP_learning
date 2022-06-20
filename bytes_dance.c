#include"bytes_dance.h"

void show_bytes(byte_pointer s, size_t len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%x\n", s[i]);
    }
    
}

void show_int(int t)
{
    show_bytes((byte_pointer) &t, sizeof(int));
}

void show_long(long t)
{
    show_bytes((byte_pointer) &t, sizeof(long));
}

void show_short(short t)
{
    show_bytes((byte_pointer) &t, sizeof(short));
}

void show_double(double t)
{
    show_bytes((byte_pointer) &t, sizeof(double));
}

int is_little_endian(void)
{
    int test = 0x1234;
    return is_little_endian_judge(test);

}

int is_little_endian_judge(int test)
{
    byte_pointer s = (byte_pointer) &test;
    int i = 0;
    if (s[i]==0x34)
    {
        return 1;
    }
    else if(s[i]==0x12)
    {
        return 0;
    }
    else
    {
        printf("Error");
        exit(1);
    }
}

unsigned replace_byte(unsigned *x, int t, unsigned char b)
{
    byte_pointer px = (byte_pointer) x;
    px[4-t]=b;
    return 0;
}

//2.61 对于int型特殊位形式的判断

bool is_all_one(int x)
{
    return !~x;
}

bool is_all_zero(int x)
{
    return !x;
}

bool is_low_one(int x)
{
    return !((x ^ 0xff)<<24);
}

bool is_high_zero(int x)
{
    return !(x & 0xff000000);
}

//2.62 对于int型特殊位形式的判断
bool int_shift_are_arithmetic(void)
{
    int test = 0xffffffff;
    return !~(test>>32);
}

//2.63 
unsigned srl(unsigned x, int k)
{
    unsigned xsra = (int) x >>k;
    int w = sizeof(int)<<3;
    int mask = -1<<(w-k);

    return xsra&(~mask);
}

unsigned sra(int x, int k)
{
    int xsra = (unsigned) x >>k;
    int w = sizeof(int)<<3;
    int mask = -1<<(w-k);
    int mmask = -1<<(w-1);

    mask = mask &(!(mmask&x-1));

    return xsra|mask;
}

//2.64

bool any_odd_one(unsigned x)
{
    unsigned mask  = 0xaaaaaaaa;

    return !!(x&mask);
    
}

//2.65

bool odd_ones(unsigned x)
{
    x = x^(x>>1);
    x = x^(x>>2);
    x = x^(x>>4);
    x = x^(x>>8);
    x = x^(x>>16);

    return x&0x1;
}

//2.66
bool leftmost_ones(unsigned x)
{
    x|= x>>1;
    x|= x>>2;
    x|= x>>4;
    x|= x>>8;
    x|= x>>16;

    return (x>>1) + (x &&1);
}