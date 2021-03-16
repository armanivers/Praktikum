#include "vector.h"

Vector::Vector(int d) : d{d}, m{new double[d]} {}

Vector::Vector(const Vector& o)
{
    for(int i = 0 ; i < o.getD(); i++)
    {
        m[i] = o.getM()[i];
    }
}

Vector::~Vector()
{
    delete[] (m);
}

void Vector::set(int p, double d)
{
    m[p] = d;
}

Vector Vector::operator*(const double skalar) const
{
    Vector result(d);
    for(int i = 0; i < d; i++)
    {
        result.m[i] = m[i]*skalar;
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << "(";
    int k = v.d-1;
    for(int i = 0 ; i < v.d; i++)
    {
        out << v.m[i];
        
        if(k > 0) 
        {
            out << ",";
            k--;
        }
    }
    out << ")";
    return out;
}