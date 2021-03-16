#include <stdio.h>
#include <string.h>

void test1(int* p)
{
    // dadurch direkten zugriff auf die variable
    *p = 10;
}

void test2(const int* p)
{
    // dadurch KEINEN zugriff auf die variable, da es const ist!
    //*p = 10;
    // const int* p wird zu read only !
}

void test3(int array[],int n)
{
    for(int i = 0 ; i < n; i++)
    {
        array[i] = -1;
    }
}

void test4(int* array,int n)
{
    for(int i = 0 ; i < n; i++)
    {
        array[i] = -1;
    }
}

void printArray(int a[],int n)
{
    for(int i = 0 ; i < n; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

int main()
{

    int a = 5;
    int* p = &a;
    printf("%d Adresse: %p \n",a,p);
    test1(p);
    printf("%d Adresse: %p \n",a,p);

    int array[] = {1,2,3,4,5};
    printArray(array,5);
    test4(array,5);
    printArray(array,5);
    // array in main wird referenziert und bearbeitet
    // arrays passed by reference! (immer referenz also zeiger wird erwartet) Funktionen test3 und 4 sind gleich
    
    char str1[6] = "hallo";
    // muss 6 sein also length+1, wegen \0 zeichen, sonst speicherfehler
    char str2[] = "hallo";
    printf("%d, %d \n", strlen(str1),strlen(str2));

    return 0;
}
