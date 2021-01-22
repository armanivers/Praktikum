#include "medium.h"

// static variable initialisieren
int Medium::counter = 0;

Medium::Medium(std::string titel, int jahr) : titel{titel}, jahr{jahr}, id{counter++}
{
    // id ist readonly (const) und es kann nicht im konstruktor normal gesetzt werden, deswegen oben in der konstruktorliste!
    
    // id = counter;
    // counter++;
}

// reicht in .h falls Destruktor kein inhalt bestizt, sonst cpp
// Medium::~Medium(){}

/*
//inline kann in cpp implementiert werden, schoner aber direkt in .h
inline int Medium::getJahr() const
{
    return jahr;
}
*/

int Medium::alter()
{
    return 2021 - getJahr();
}

// pure virtual keine implementierung!

//void Medium::druckeDaten()
//{
//    std::cout << "ID = " << id << " \"" << titel << "\""; // << std::end;
//}