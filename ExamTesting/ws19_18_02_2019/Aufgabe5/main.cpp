#include <iostream>
#include "vector.h"

int main()
{
    Vector<int> v1(2);
    v1.set(0,1);
    v1.set(1,2);

    // das geht nicht, falls std::ostream als member und friend deklariert ist!
    // oder template <class u> nutzen!!
    std::cout << v1 << std::endl;

    std::cout << v1[0] << "|" << v1[1] << std::endl;

    return 0;
}