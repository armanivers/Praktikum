#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatString(const char* str1, const char* str2)
{
    int size = strlen(str1)+strlen(str2)+1;
    char* neu = malloc(sizeof(char)*size);
    
    if(neu == NULL) return NULL;

    int i = 0;
    while(*str1 != '\0')
    {
        neu[i] = *str1;
        str1++;
        i++;
    }
    while(*str2 != '\0')
    {
        neu[i] = *str2;
        str2++;
        i++;
    }
    neu[i] = '\0';
    return neu;
}


int main()
{
    printf("%s",concatString("Hallo du bist ","ein opfer!"));
    return 0;
}