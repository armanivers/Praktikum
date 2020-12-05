#include <stdio.h>
#include "dictionary.h"

int main()
{
    int SIZE = 2;
    init();
    int i;

    for(i = 1; i <= 2 * SIZE; i++){
        printf("insert %d\n", insert(i));
    }

    //displayDictionary();
    for(i = 1; i <= SIZE; i++){
        printf("member %d\n", member(i));
    }

    for(i = SIZE+1; i <= 2*SIZE; i++){
        printf("delete %d\n", delete(i));
    }

    for(i = 1; i <= 2*SIZE; i++){
        printf("member %d\n", member(i));
    }
    
    printf("\n");

    return 0;
}