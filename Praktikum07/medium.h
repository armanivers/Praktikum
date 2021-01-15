#ifndef _MEDIUM_H
#define _MEDIUM_H
#include <string>
#include <iostream>

// eine Klasse abtrakt, sobald sie mindestens eine rein virtuelle Funktion enthaelt
class Medium
{
    private:
    // const = readonly (in java final)
    const int id;
    static int counter;

    std::string titel;
    int jahr;

    public:
    Medium(std::string titel, int jahr);

    virtual ~Medium(){}

    // in der Klasse implementiert direkt inline und const!
    inline std::string getTitel() const
    {
        return titel;
    }

    inline int getJahr() const
    {
        return jahr;
    }

    inline int getId() const
    {
        return id;
    }

    /*
    inline sollte immer in .h implementiert werden, es geht auch in cpp aber nicht schoen
    int getJahr();
    */

    // in cpp implementieren
    int alter();

    // = 0 macht die virtuelle Funktion "pure virtual", rein virtuelle Funktion
    virtual void druckeDaten() = 0;

};
#endif