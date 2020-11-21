#include <stdio.h>
#include "dictionary.h"

int main()
{
    init();
    
    /*
    printf("%d \n",insert(76));
    displayDictionary();
    printf("%d \n",insert(93));
    displayDictionary();
    printf("%d \n",delete(40));
    displayDictionary();
    printf("%d \n",insert(47));
    displayDictionary();
    printf("%d \n",member(93));
    */

    
    init();
    displayDictionary();
    printf("%d \n",insert(1));
    displayDictionary();
    printf("%d \n",insert(3));
    displayDictionary();
    printf("%d \n",delete(3));
    displayDictionary();
    printf("%d \n",insert(5));
    displayDictionary();
    printf("%d \n",member(5));
    displayDictionary();
    
    return 0;
}