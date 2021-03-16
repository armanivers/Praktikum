#ifndef _RATIONAL_H_
#define _RATIONAL_H_
#include <ostream>
class Rational
{
    private:
    int zahler;
    int nenner;

    public:
    Rational(int zahler, int nenner);
    Rational(const Rational& o);
    ~Rational();

    // Member Funktionen, deswegen kein friend notwendig!
    Rational operator*(const Rational& r);
    Rational operator*(const int s) const; 

    // globale Funktionen, deswegen mit friend!
    friend Rational operator*(const int s,const Rational& r);
    friend std::ostream& operator<<(std::ostream& out, const Rational& r);

};
#endif