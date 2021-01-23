#include "stack.h"
#include <iostream>

int main()
{
    using namespace fhdo_pk2;
    
    std::cout << "Start" << std::endl;

    int stackSize = 10;
    Stack<int> stack(stackSize);


    for(int i = 0; i < stackSize; i++)
    {
        stack.push(i);
    }

    std::cout << stack << std::endl;
    std::cout << "-----------------" << std::endl;
    for(int i = 0 ; i < 3; i++)
    {
        std::cout << "I Popped " << stack.pop() << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    std::cout << stack << std::endl;

    for(int i = 0 ; i < 10; i++)
    {
        std::cout << "I Popped " << stack.pop() << std::endl;
    }
    std::cout << "-----------------" << std::endl;
    std::cout << stack << std::endl;

    return 0;
}