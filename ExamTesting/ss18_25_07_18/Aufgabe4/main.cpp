#include "vector.h"
#include <iostream>

int main()
{
    Vector v(2);

    v.set(0,1);
    v.set(1,2);

    // ausgabe von v*2 geht nicht?? => DOCH WENN ES CONST IST
    Vector v2 = v*2;

    std::cout << v*2 << std::endl;
    std::cout << v2 << std::endl;
    return 0;
}