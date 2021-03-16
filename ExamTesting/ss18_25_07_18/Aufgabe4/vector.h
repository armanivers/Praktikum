#ifndef _VECTORH_
#define _VECTORH_

#include <ostream>

class Vector
{
    private:
    int d;
    double* m;

    public:
    Vector(int d);
    Vector(const Vector& o);
    ~Vector();

    inline int getD() const
    {
        return d;
    }

    inline double* getM() const
    {
        return m;
    }

    void set(int p, double d);

    // friend nur globale funktionen!
    Vector operator*(const double skalar) const; // const weil wir sagen, dass wir an der linken seite nichts kaputt machen
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);

};
#endif