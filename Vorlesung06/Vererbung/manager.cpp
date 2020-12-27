#include "manager.h"

Manager::Manager(char *name, double gehalt, double bonus) : Angestellter(name,gehalt), bonus{bonus} {}

void Manager::setBonus(double bonus) {
    // kein this.bonus = bonus??
    bonus = bonus;
}

/* override nur in .h?
void Manager::berechneJahreszahlung() override
{
    return Angestellter::berechneJahreszahlung() + bonus;
}
*/