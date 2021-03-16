#include "rational.h"

Rational::Rational(int zahler, int nenner) : zahler{zahler},nenner{nenner} {}

Rational::Rational(const Rational& o)
{
    zahler = o.zahler;
    nenner = o.nenner;
}

Rational::~Rational()
{
    // nicht notwendig, da nichts dynamisch erzeugt wird
}

Rational Rational::operator*(const Rational& r)
{
    return Rational(zahler+r.zahler,nenner+r.nenner);
}

Rational Rational::operator*(const int s) const
{
    return Rational(zahler*s, nenner*s);
}

Rational operator*(const int s,const Rational& r)
{
    return r * s;
}

std::ostream& operator<<(std::ostream& out, const Rational& r)
{
    out << r.zahler << "|" << r.nenner;
    return out;
}
