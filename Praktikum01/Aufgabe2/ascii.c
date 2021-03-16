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

void asciiTest(int s)
{
    /*
    char c = (char)32;
    printf("%d %c",c,c);
    c++;
    printf("%d %c",c,c);
    int zahl = (int)c;
    printf("%d %d",zahl,c);
    */

    char c = 32;
    while( ((int) c) < 126)
    {
        for(int i = 0; ((i < s) && ((int)c) < 126); i++)
        {
            printf("%d     %c ",c,c);
            c++;
        }
        printf("\n");
    }
    
}