#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <iomanip>

// compile with g++ -o stream streamManipulators.cpp
// ./stream
int main()
{
    std::cout << std::setfill('0') << std::right << std::setw(4) << 12 << std::endl;
    // Ausgabe: 0012
    return 0;
}