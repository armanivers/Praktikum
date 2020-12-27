#include "angestellter.h"

class Manager : public Angestellter{
private:
    double bonus;
public:
    Manager(char *name, double gehalt, double bonus);
    
    void setBonus(double bonus);
    
    double getBonus() const
    {
        return bonus;
    }

    double berechneJahreszahlung() override
    {
        return Angestellter::berechneJahreszahlung() + bonus;
    }

    inline void inheritanceTest()
    {
        std::cout << "Manager " << std::endl;
    }
};