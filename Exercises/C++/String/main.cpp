#include "string.h"
#include <iostream>

int main()
{
    using namespace fhdo_pk2;
    using namespace std;

    // ist default konstruktor nicht String s1(); ??
    String s1;

    // warum ist die ausgabe 1??
    cout << s1 << endl;

    // Alternative
    String s2{};
    cout << s2 << endl;

    String s3("Hellooo");
    cout << s3 << endl;
    
    // oder auch ohne const
    const char text[] = "World"; 

    String s4(text);
    cout << s4 << endl;

    String s5 = s4;
    cout << s5 << endl;

    return 0;
}