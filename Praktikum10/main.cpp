#include "matrix.h"
#include <iostream>

int main()
{
    using namespace fhdo_pk2;

    Matrix<int> m(2);

    m.set(0,0,1);
    m.set(0,1,2);
    m.set(1,0,3);
    m.set(1,1,4);

    std::cout << m << "*" << std::endl << m << "=" << std::endl << m*m;

    return 0;
}