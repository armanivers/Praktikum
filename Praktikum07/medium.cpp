#include "medium.h"

// static variable initialisieren
int Medium::counter = 0;

Medium::Medium(std::string titel, int jahr) : titel{titel}, jahr{jahr}
{
    id = counter;
    counter++;
}

// reicht das? Ist das uberhaupt notwendig?
Medium::~Medium()
{

}

/*
// nicht in der klasse implementiert, damit es inline ist muss "inline" hier stehen!
inline int Medium::getJahr() const
{
    return jahr;
}
*/

int Medium::alter()
{
    return 2020 - getJahr();
}

void Medium::druckeDaten()
{
    std::cout << "ID = " << id << " \"" << titel << "\""; // << std::end;
}