#include <stdio.h>

int stringCompare(char* s, char* t)
{
    int i = 0;
    
    // Fall 1: s oder t erreichtt endzeichen, Fall 2: s==t
    while( (*(s+i) != '\0') && (*(t+i) != '\0') && (*(s+i)==*(t+i)))
    {
        i++;
    }
    
    if(*(s+i) == *(t+i)) return 0;

    int differenz = *(s+i)-*(t+i);

    return differenz>0 ? 1 : -1;
}

int main()
{

    printf("strcmp(\"a\", \"a\") = %d\n", stringCompare("a", "a") );
    printf("strcmp(\"a\", \"b\") = %d\n", stringCompare("a", "b") );
    printf("strcmp(\"a\", \"c\") = %d\n", stringCompare("a", "c") );
    printf("strcmp(\"z\", \"d\") = %d\n", stringCompare("z", "d") );
    printf("strcmp(\"abc\", \"abe\") = %d\n", stringCompare("abc", "abe") );
    printf("strcmp(\"apples\", \"apple\") = %d\n", stringCompare("apples", "apple") );

    return 0;
}