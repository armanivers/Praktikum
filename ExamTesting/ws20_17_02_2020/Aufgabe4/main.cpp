#include "mystring.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>

int main()
{
    // wenn man String s1(); schreibt, dann bei ausgabe 1 statt leer?
    String s1;
    String s2("Hallo");

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    
    std::cout << s2[0] << std::endl;
    std::cout << s2.at(0) << std::endl;

    String s3(s2);
    std::cout << s3 << std::endl;


    // test of c_str()
    String str ("Please split this sentence into tokens");

    char * cstr = new char [str.length()+1];
    std::strcpy (cstr, str.c_str());

    // cstr now contains a c-string copy of str

    char * p = std::strtok (cstr," ");
    while (p!=0)
    {
        std::cout << p << '\n';
        p = std::strtok(NULL," ");
    }
    delete[] cstr;

    return 0;
}