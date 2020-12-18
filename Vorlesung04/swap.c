#include <stdio.h>

void swap(int *zahl1, int *zahl2);

int main()
{
    int zahl1 = 5;
    int zahl2 = 10;

    int *pzahl1 = &zahl1;
    int *pzahl2 = &zahl2;

    printf("Zahl1 = %d, Zahl2 = %d \n",*pzahl1,*pzahl2);
    // bzw. hier &zahl1 under &zahl2 ubergeben, statt zwei Zeiger zu erstellen
    swap(pzahl1,pzahl2);
    printf("Zahl1 = %d, Zahl2 = %d \n",*pzahl1,*pzahl2);
}

void swap(int *zahl1, int *zahl2)
{
    int temp = *zahl1;
    *zahl1 = *zahl2;
    *zahl2 = temp;
}