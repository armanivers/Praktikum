#include <stdio.h>

void ausgabe(int wert, int differenz,int mal){
  int i;
  for(i = 0; i <= differenz; i++){
    //wert = wert + i * mal;
    printf("%d ", (wert+i*mal));
  }
}

void multiply(int max, int min)
{
  int differenz = min - max;

  printf("Von = %d\n", max);
  printf("Bis = %d\n", min);
  printf("Differenz: %d\n", differenz);
  
  for (int i=0; i< 10 ; i++){
    ausgabe(max+i*10,differenz,i+1);
    printf("\n");
  }
}