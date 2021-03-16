#ifndef _VECTORH_
#define _VECTORH_

#include <iostream>

class Vector
{
    private:
    int n;
    double* m;

    public:
    Vector(int n);
    Vector(const Vector& o);
    ~Vector();

    int getN() const;
    double getM(int p) const;
    
    void set(int p,double k);

    // wenn es friend ist, muss es als "member funktion sein"
    double operator[](int p);

    friend std::ostream& operator<<(std::ostream& ausgabe, const Vector& v);

};
#endif