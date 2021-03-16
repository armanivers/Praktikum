#include <stdio.h>

void stringcat(char* s, const char* t)
{
    int i = 0;
    // ende von destination-string finden
    while(*(s+i) != '\0')
    {
        i++;
    }

    int j = 0;
    while(*(t+j) != '\0')
    {
        s[i] = t[j];
        j++;
        i++;
    }
    s[i] = '\0';
}

int main()
{
    char leer[20] = "123";
    char source[20] = "hallo";

    printf("%s %s \n",leer,source);

    stringcat(leer,source);
    printf("%s \n",leer);
    
    int i = 0;
    while(leer[i] != '\0')
    {
        printf("%c",leer[i]);
        i++;
    }
    return 0;
}