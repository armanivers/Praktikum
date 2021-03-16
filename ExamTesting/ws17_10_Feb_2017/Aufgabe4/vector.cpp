#include "vector.h"

Vector::Vector(int n) : n{n}, m{new double[n]} {}

Vector::Vector(const Vector& o) : Vector(o.getN())
{
    for(int i = 0; i < o.n; i++)
    {
        set(i,o.m[i]);
    }
}

Vector::~Vector()
{
    delete[] m;
}

int Vector::getN() const
{
    return n;
}
double Vector::getM(int p) const
{
    return m[p];
}

void Vector::set(int i, double k)
{
    m[i] = k;
}

double Vector::operator[](int i)
{
    //if(i < 0 || i > n) throw std::out_of_range("error");
    return m[i];
}

std::ostream& operator<<(std::ostream& ausgabe, const Vector& v)
{
    for(int i = 0; i < v.n; i++)
    {
        ausgabe << v.m[i] << std::endl;
    }

    return ausgabe;
}