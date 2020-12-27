#include <iostream>
// sollte ich hier nicht manager und angesteller includen?? 
// wenn ich angesteller include, dann wird es auch bei manager included in der .h datei -> problem??
#include "manager.h"

int main()
{
    Angestellter *a;
    Manager *m;
    a = new Angestellter("Meier", 5000.00);
    m = new Manager("Obermeier", 10000.00, 50000.00);

    a->inheritanceTest();
    m->inheritanceTest();

    std::cout << a->berechneJahreszahlung() << std::endl;
    std::cout << m->berechneJahreszahlung() << std::endl;

    a = m;

    a->inheritanceTest();
    std::cout << a->berechneJahreszahlung() << std::endl;

    return 0;

    // Aufruf von virtuelle Funktionen abhangig von Typ des Objekts, nicht vom Typ des zeigers!
    // deswegen wird nach der Zuweisung "a = m" berechneJahreszahlung() von Manager aufgerufen!
    // --> DYNAMISCHE BINDUNG!
    // (was rechts steht!)

    // BEISPIEL: Methode inheritanceTest(), wird einfach uberschrieben obwohl es nicht virtual ist
    // Bei eine Reimplementierung von Funktionen aus Oberklassen in Unterklassen 
    // hangt des von Typ des ZEIGERS ab!
    // --> STATISCHE BINDUNG!
    // (was links steht!)
}