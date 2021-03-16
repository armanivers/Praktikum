#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    // Kein Problem! Hier wird der von a reservierte Speicher einfach durch B ersetzt
    char a = 'A';
    char *pointer = &a;
    *pointer = 'B'; // falls hier mehr als ein character stehen wurde, dann fuhrt es zu overlfow, da wird speicher nur fur 'A' haben
    free(pointer);
    */

    /*
    // auch kein Problem?
    int * ptr; 
    ptr[0] = 5;
    */

    // kein problem
    int *pointer = malloc(8);
    pointer[5] = 0;

    return 0;
}