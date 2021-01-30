#include "string.h"
#include <iostream>
using namespace fhdo_pk2;

String::String()
{
    std::cout << "Konstruktor 1" << std::endl;
    size = 1;
    str = new char[size];
    str[0] = '\0';
}

String::String(const char* s)
{
    std::cout << "Konstruktor 2" << std::endl;
    size = strlen(s);
    str = new char[size];

    //strcpy(str,s);
    
    const char *temp = s;
    int i = 0;

    while(*(temp+i) != '\0')
    {
        str[i] = *(temp+i);
        i++;
    }
    

    /*
    for(int i = 0; i < size ; i++)
    {
        str[i] = (*s+i);
    }
    */
}

String::String(const String& s)
{
    std::cout << "Copy-Konstruktor" << std::endl;
    size = s.size;
    str = new char[size];

    for(int i = 0; i < size; i++)
    {
        str[i] = s.str[i];
    }
}

String::~String()
{
    std::cout << "Destruktor" << std::endl;
    delete[](str);
}


// geht das nie in cpp datei??
// muss ich einige faelle << operator in .h direkt als friend implementieren?
/*
ostream& operator<< (ostream& ausgabe, const String& s)
{
    // length attribut war eigentlich private in .h, aber sonst kein zugriff?? (loesung ohne getter?)
    
    for(int i = 0 ; i < s.getLength() ; i++)
    {
        ausgabe << s.getChar(i);
    }
    
    ausgabe << "hallo";
    return ausgabe;
}
*/