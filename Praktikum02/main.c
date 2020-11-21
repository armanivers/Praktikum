#include <stdio.h>
#include "uppercaseWriter.h"
#include "queue.h"

int main()
{
    //Uppercase single char 
    char a = 97;
    printf("Char = %c \n" ,a);
    printf("Uppercase Char = %c \n", to_upper_case(a));

    //Uppercase char array 
    char text[22] = "Hallo123EsIsteinTEST!";
    printf("Lowercase Text = %s \n",text);
    upper(text);
    printf("Uppercase Text = %s \n",text);
    
    //Queue
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("%i",dequeue());

    enqueue(3);
    printf("%i",dequeue());
    printf("%i",dequeue());
    printf("%i",dequeue());

    enqueue(4);
    enqueue(5);

    printf("%i",dequeue());
    printf("%i",dequeue());    

    return 0;
}