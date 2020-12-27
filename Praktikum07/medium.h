#ifndef _MEDIUM_H
#define _MEDIUM_H
#include <string>
#include <iostream>

// eine Klasse abtrakt, sobald sie mindestens eine rein virtuelle Funktion enthaelt
class Medium
{
    private:
    int id;
    static int counter;

    std::string titel;
    int jahr;

    public:
    Medium(std::string titel, int jahr);

    // in der Klasse implementiert direkt inline!
    inline std::string getTitel() const
    {
        return titel;
    }
    // nicht in der klasse implementiert, damit es inline ist muss "inline" hier stehen!
    inline int getJahr() const
    {
        return jahr;
    }

    /*
    // wenn ich nicht inline schreiben und nur int getJahr() const {return jahr} automatisch inline weil implementeirt?
    // inline immer in .h direk definieren oder geht es so zu machen und dann in .cpp zu erganzen
    int getJahr();
    */

    // einach virtuellen destruktor ohne nichts reicht?
    virtual ~Medium();

    // in cpp implementieren
    int alter();

    // = 0 macht die virtuelle Funktion "pure virtual", rein virtuelle Funktion
    virtual void druckeDaten() = 0;

};
#endif