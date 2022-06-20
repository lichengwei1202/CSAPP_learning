#include <stdio.h>
#include <string.h>

void inplace_swap(int *x, int *y);
void reverse_array(int a[], int cnt);
int main(void)
{
    int test[5]={1,2,3,4,5};
    reverse_array(test, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d",test[i]);
    }
    
    return 0;
}

void reverse_array(int a[], int cnt)
{
    int first, last;

    for ( first = 0, last = cnt-1;first<last; first++, last--)
    {
        inplace_swap(&a[first],&a[last]);
    }
    
}
void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}