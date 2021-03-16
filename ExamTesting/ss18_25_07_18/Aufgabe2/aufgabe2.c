#include <stdio.h>

void ausgabe (int **z){
    printf("Adresse von a: %p\n",&(**z));
    printf("Adresse von z1: %p\n",&(*z));
    printf("Adresse von z2: %p\n",&z); // adresse von z2 geht nicht
    printf("a hat den wert: %d\n",**z);
}

int main(){
    
    int a=5;
    int *z1 = &a;
    int **z2= &z1;
    
    printf("Adresse von a: %p\n", &a);
    printf("Adresse von z1: %p\n", &z1);
    printf("Adresse von z2: %p\n", &z2);
    printf("a hat den wert: %d\n", a);

    ausgabe(z2);
}