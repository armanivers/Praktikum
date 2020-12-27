#include <iostream>

int main()
{
    int a=0;
    int& ref = a;
    ref=1;
    ref++;
    std::cout << "a=" << a << std::endl;
    return 0;
}