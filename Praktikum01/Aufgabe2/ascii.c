#include <stdio.h>

void ascii(int s)
{
    int counter = 1;

    for(int i = 32; i < 127; i++)
    {
        if(counter > s)
        {
            printf("\n");
            counter = 1;
        }
        printf("%d     %c ",i,i);
        counter++;
    }
}