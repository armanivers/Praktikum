#include <stdio.h>

int main()
{
    int a = 100, b = 101;
    int *c[2];
    c[0]=&a;
    c[1]=&b;
    int **z;
    z = &c[0];
    **z = b++;
    **(z+1) = b;

    printf("a = %d, b = %d", a, b);
}