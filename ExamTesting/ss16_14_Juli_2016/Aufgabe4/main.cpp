#include "vector.h"

using namespace fh_do;

int main()
{
    Vector<int>* a = new Vector<int>(3);
    a->set(0,0);
    a->set(1,1);
    a->set(2,2);

    Vector<int> b(3);
    b.set(0,0);
    b.set(1,1);
    b.set(2,2);

    std::cout << *a << std::endl;
    std::cout << b << std::endl;

    std::cout << b*5 << std::endl;
    
    return 0;
}