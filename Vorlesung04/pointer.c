#include <stdio.h>
int main()
{ 
    int x, y;
    int z[] = {4,2,1};
    int *ptra, *ptrb;
    ptra = &z[2];
    x = *ptra - 2;
    y = *(ptra - 1) - 2;
    ptrb = ptra - 1;
    *ptrb = 0;
    *(z+2) = 2;
    z[0] = 2;
    printf("%d, %d, %d, %d, %d",z[0],z[1],z[2],x,y);
    return 0;
}