#include <stdlib.h>
#include <stdio.h>

int main()
{

    // A)

    // Fehler, puffer wird nicht dynamisch erzeugt, also es befindet sich im Stack
    //char* puffer = malloc(10*sizeof(char));
    
    // free benutzt man bei dynamisch erzeugte Objekte, die im Heap liegen
    //free(puffer);
    
    // Loesung: speicher fur den Puffer reservieren => char* puffer = malloc(10*sizeof(char
  
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // B)
    // Fehler, da es nur ein Pointer erzeugt wird, dieser kann nicht mit index angesprochen werden, da es sich nicht um ein char array handelt
    
    //char* pointer;
    // somit ist pointer[0] eine nicht definierte Adresse im Speicher
    
    //pointer[0] = 'A';
    //printf("%c",pointer);
    
    // Loesung: ein array initialisieren => char* pointer[1]; danach kann man auch die Position 1 erreichen

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // C)
    // keine Fehler
    char c = 'F';
    char* puffer = &c;
    free(puffer);

    return 0;
}