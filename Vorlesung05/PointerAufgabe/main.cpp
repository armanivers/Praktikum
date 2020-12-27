#include <iostream>

int main()
{
    int *pointer;
    pointer = new int;
    *pointer = 10;
    int *pa = new int[4];
    pa[2] = 15;
    int **pp = new int*[2];
    pp[0] = pointer;
    *(pp+1) = &pa[2];
    std::cout << *pp[0] << std::endl;
    std::cout << **pp << std::endl;
    std::cout << *pp[1] << std::endl;
}