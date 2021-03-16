#include "vector.h"
#include <iostream>

int main()
{
    Vector v1(2);
    v1.set(0,1);
    v1.set(1,2);

    Vector v2(2);
    v2.set(0,1);
    v2.set(1,2);

    std::cout << v1 << std::endl;

    return 0;
}