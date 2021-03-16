#include <iostream>

int main()
{
    int a=0;
    int& ref = a;
    ref=1;
    ref++;
    std::cout << "Referenz a=" << ref << " Original a=" << a<< std::endl;
    return 0;
}

//g++ -o main main.cpp