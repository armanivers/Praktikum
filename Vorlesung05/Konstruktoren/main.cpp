#include "punkt.h"
#include <iostream>

int main(){
    Punkt p1;
    Punkt p2 {};

    Punkt* p3 = new Punkt(10,20);
    
    // Aufgabe VL 05 Folie 6 

    std::cout << "X = " << p1.getX() << " Y = " << p1.getY() << std::endl;
    std::cout << "X = " << p2.getX() << " Y = " << p2.getY() << std::endl;
    std::cout << "X = " << p3->getX() << " Y = " << p3->getY() << std::endl;
}