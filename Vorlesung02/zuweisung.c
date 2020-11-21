#include <stdio.h>

int main(){
    int a,b,c,wert;
    a = b = c = 0;
    wert = a * (4 - (a = 2));
    printf("%d",wert);
    // Ausgabe = 4
    return 0;
}