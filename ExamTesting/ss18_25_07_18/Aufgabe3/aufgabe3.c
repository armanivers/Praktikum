#include <stdio.h>

int atoi(char* c)
{
    int result = 0;
    int i = 0;

    while(c[i] != '\0')
    {
        result = result * 10 + c[i] - '0';
        i++;
    }
    return result;
}

int main()
{
    char s[] = "12341";
    printf("%d \n",atoi(s));
    return 0;
}