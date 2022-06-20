#include <stdio.h>
#include <string.h>
#include "show_bytes.h"

int main(void)
{
    int a = 0x89abcdef;
    int b = 0x765432ef;
    int c = 0x0;
    byte_pointer ap = (byte_pointer) &a;
    byte_pointer bp = (byte_pointer) &b;
    byte_pointer cp = (byte_pointer) &c;

    cp[0]=bp[0];
    
    for (int i = 1; i < sizeof(a); i++)
    {
        cp[i]=ap[i];
    }
    
    show_int(c);
    return 0;
}