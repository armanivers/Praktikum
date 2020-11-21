#include <stdio.h>
#include <conio.h>
#include "ggt.h"

int main() 
{  
    int a = 10;
    int b = 3;

    printf("a = %i, b = %d\n",a,b);
    printf("GGT von a und b = %i\n",ggt(a,b));
    
    // prevent closing
    _getch();
    return 0;
}