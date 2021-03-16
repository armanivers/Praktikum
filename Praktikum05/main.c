#include <stdio.h>
#include "countspace.h"
#include "min.h"
#include "stringcat.h"
#include "factorial.h"

int main()
{
    //A1
    char a[25] = "a rt  24as4      !";
    
    printf("A1: Anzahl = %d \n",countIndex(a));
    printf("A1: Anzahl = %d \n",countPointer(a));
    
    //A2
    double b[] = {1.0, 5.0, 3.0, 8.0, 0.5};
    //min funktion erwartet ein double array und int mit anzahl von array elemente
    printf("A2: Min = %f \n", min(b,5));

    //A3
    char array1[] = "Hallo ";
    char array2[] = "Welt";

    char *result = stringcat(array1,array2);
    char *resultAlt = stringcatAlt(array1,array2);
    // Methode 1
    printf("A3: Concat = %s \n",result);
    printf("A3: ConcatAlt = %s \n",resultAlt);
    // Methode 2: dadurch dass const erwartet wird, ist sowas moglich
    printf("A3: Const Test = %s \n",stringcat("Hallo ","das ist ein test"));
    // Methode 3:
    /*
    while(*result != '\0')
    {
        printf("c =%c \n",*result++);
    }
    */

    //A4
    int zahl = 5;
    printf("A4: Fakultat von %d ist %d \n",zahl,factorial(zahl));
    int n = 49; 
    int k = 6;
    printf("A4: Binomial Koeffizent von %d und %d ist %d \n",n,k,binomialCoefficient(n,k));
    return 0;
}