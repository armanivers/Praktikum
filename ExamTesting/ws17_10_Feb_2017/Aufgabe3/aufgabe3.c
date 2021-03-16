#include <stdio.h>

int strcompare(char* s, char* v)
{
    while(*s != '\0' || *v != '\0')
    {
        if(*s > *v) return 1;
        if(*v > *s) return -1;

        s++; v++;
    }
    return 0;
}

int main()
{
    // array lieft schon ein pointer zuruck!!
    char t1[10] = {"abc"};
    char t2[10] = {"abc"};

    char t3[10] = {"bca"};
    char t4[10] = {"abc"};

    char t5[10] = {"abc"};
    char t6[10] = {"bca"};

    printf("%d \n",strcompare(t1,t2));
    printf("%d \n",strcompare(t3,t4));
    printf("%d \n",strcompare(t5,t6));

    return 0;
}