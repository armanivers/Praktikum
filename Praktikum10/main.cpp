#include "matrix.h"
#include <iostream>

int main()
{
    using namespace fhdo_pk2;

    Matrix<int> m1(2);

    m1.set(0,0,1);
    m1.set(0,1,2);
    m1.set(1,0,3);
    m1.set(1,1,4);

    Matrix<int> m2 = m1;

    // Kopy Konstruktor Test
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;

    // Multiplikation
    std::cout << m1 << "*" << std::endl << m1 << "=" << std::endl << m1*m1;

    // Addition
    //std::cout << m1 << "+" << std::endl << m1 << "=" << std::endl << m1+m1;

    // Subtraktion
    //std::cout << m1 << "-" << std::endl << m1 << "=" << std::endl << m1-m1;

    // Power of (^)
    //std::cout << m1 << "power of 0 is " << std::endl << (m1^0) << std::endl;

    // "==" operator (equals)
    //std::cout << m1 << "-" << std::endl << m2 << "are equal? " << (m1==m2) << std::endl;
    
    // "-" operator (Negation)
    //std::cout << m1 << "negated is " << std::endl << (-m1) << std::endl;
    
    return 0;
}