#include <stdio.h>
#include <string.h>

unsigned int bool_equal(int *x, int *y);

int main(void)
{
    int a=25, b=25;
    printf("%d",bool_equal(&a, &b));

    return 0;
}

unsigned int bool_equal(int *x, int *y)
{
    return !(~(*x ^ ~*y));
    
}