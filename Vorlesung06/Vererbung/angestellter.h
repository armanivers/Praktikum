#include <iostream>

class Angestellter {
    char *name;
    double gehalt;
public:
    Angestellter(char *name, double gehalt);
    
    void setName(char* name);
    void setGehalt(double gehalt);
    
    // hier implementiert nur wenn es inline ist??
    inline char* getName() const{
        return name;
    }
    inline double getGehalt() const{
        return gehalt;
    }

    virtual double berechneJahreszahlung();

    inline void inheritanceTest()
    {
        std::cout << "Angestellter " << std::endl;
    }
};