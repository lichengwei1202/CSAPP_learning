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

//2.67

int int_size_is_32(void)
{
    int set_msb = 1<<31;

    return set_msb && set_msb<<1;
}

//2.68 返回一个整数，其二进制从最低位开始的n位为1， 其余为0；

int lower_one_mask(int n)
{
    int base = 0x80000000;

    return ~(base>>(32-n-1));
}

//2.69 返回一个二进制数，按照n循环左移
int rotate_left(unsigned x, int n)
{
    int w = sizeof(int)<<3;

    return (x<<n)|(x>>(w-n));
}

//2.70 判断一个n位的补码，能够表示的数的范围为大

int fit_bits(int x, int n)
{
    int w = sizeof(int)<<3;

    return x == x<<(w-n)>>(w-n);
}

//2.71 将一个字长为4的字中的第n个字节截取出来扩展成一个新的字（32位）

/*先对字进行封装*/
typedef unsigned packed_t;

int xbyte(packed_t n, int bytenum)
{
    int w = sizeof(packed_t);
    return (int) n<<((w-bytenum-1)<<3)>>((w-1)<<3);
}

//2.72 将一个整数复制进一个缓冲buf里，如果buf的空间不够时，则不执行该操作

void copy_int(int val, void *buf, int maxbytes)
{
    if (maxbytes - (int) sizeof(buf)>=0)
    {
        memcpy(buf, (void *) &val, sizeof(val));
    }
    
}

//2.73 

int saturating_add(int x,int y)
{
    int sum = x+y;
    int mask = INT_MIN;
    int pos_over = !(x&mask)&&!(y&mask)&&(sum&mask);
    int neg_over = (x&mask)&&(y&mask)&&!(sum&mask);
    (pos_over&&(sum=INT_MAX))||(neg_over&&(sum=INT_MIN));//这段是求教大佬得到的，实在精妙
    return sum;
}

//2.74 判断两个数相减是否会溢出

int tsub_ok(int x, int y)
{
    int sub = x-y;

    return !(x<0&&y>0&&sub>0)||(x>0&&y<0&&sub<0);
}

//2.75_1 显示无符号数乘积的高w位

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
    return ((uint64_t)((int64_t) signed_high_prod(x, y)<<(sizeof(int)<<3)))>>(sizeof(int)<<3);
}

//2.75_2 显示有符号数乘积的高w位

int signed_high_prod(int x, int y)
{
    int64_t result = (int64_t)x*y;
    return result>>(sizeof(int)<<3);
}

//2.76 以malloc函数和memset为基础模拟calloc函数，按块分配空间

void *calloc_simulate(size_t memb, size_t size)
{
    int num = memb * size;

    if (memb==num/size)
    {
        return memset(malloc(memb*size), 0, memb*size);    
    }
    else
    {
        printf("error");
        return NULL;
    }
    
}

//2.77 用位移和加减法实现乘法

int multiply_17(int x)
{
    return (x<<4)+x;
}

int multiply_minus_7(int x)
{
    return x-x<<3;
}

int multiply_60(int x)
{
    return x<<6-x<<2;
}

int multiply_minus_112(int x)
{
    return x<<4-x<<7;
}

//2.78 用位移和加减实现除法
int divide_power2(int x, int k)
{
    return (x+(1<<k)-1)>>k;//补码除法向下舍入
}

//2.79 
int mul13div4(int x)
{
    int init = x<<1+x;

    if (init/x==3)
    {
        return (init+(1<<2)-1)>>2;
    }
    else
    {
        return NULL;
    }
    
    
}

//2.80
int threefourths(int x)
{
    
}