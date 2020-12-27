#include "angestellter.h"

Angestellter::Angestellter(char *name, double gehalt) : name{name},gehalt{gehalt}{}

void Angestellter::setName(char* name)
{
    name = name;
}

void Angestellter::setGehalt(double gehalt)
{
    gehalt = gehalt;
}

double Angestellter::berechneJahreszahlung()
{
    return 12.0 * gehalt;
}

/* oder hier? bzw. mit const vor char*??
char* Angestellter::getName()
{
    return name;
}

double Angestellter::getGehalt()
{
    return gehalt;
}
*/