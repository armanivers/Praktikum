#include <stdio.h>
int main()
{
    const char* original = "C macht Spass!";
    char* duplikat;

    duplikat = original;
    printf("Original Adresse = %d, Duplikat Adresse = %d \n",*original,*duplikat);
    printf("Original = %s und Duplikat = %s \n",original,duplikat);

    original = "Nicht mehr!";
    printf("Original = %s und Duplikat = %s \n",original,duplikat);
    printf("Original Adresse = %d, Duplikat Adresse = %d \n",*original,*duplikat);

    duplikat = "Wow!";
    printf("Original = %s und Duplikat = %s \n",original,duplikat);
    printf("Original Adresse = %d, Duplikat Adresse = %d \n",*original,*duplikat);
    // beide zeigen auf dem selben Speicher, die Zeichenkette wird nicht wie gewunscht kopiert und 
    // in einem neuem Speicherbereich gespeichert
    // Referenz wird kopiert
    return 0;
}