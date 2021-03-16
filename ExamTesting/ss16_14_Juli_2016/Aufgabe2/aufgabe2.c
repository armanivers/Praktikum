#include <stdio.h>

// Teil A
static int isSpace(char c)
{
    return (c == ' ');
}

static int countSpace(const char* c)
{
    int count = 0;
    while( *c != '\0')
    {
        if(isSpace(*c)) count++;
        c++;
    }
    return count;
}

// Teil B
static double min(double a[], int n)
{
    double temp = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] < temp) temp = a[i];
    }
    return temp;
}

int main()
{
    double zahlen[] = {6.3,5.3,6.2,2.6,8.9,0.5};

    printf("Min = %f \n", min(zahlen,6));

    printf("Space anzahl = %d", countSpace("Hallo , das sollte 7 Spaces Haben! \n"));

    return 0;
}