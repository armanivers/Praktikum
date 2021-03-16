#include <stdio.h>
#include <stdlib.h>

long max(int a, int b)
{
    if(a>=b) return a;
    return b;
    // darf nicht long& sein!
}

int main()
{
    int a = 5;
    int b = 10;
    printf("%d",max(a,b));

    // kein problem
    char zeichen = 'A';
    char* ptr = &zeichen;
    free(ptr);

    return 0;
}