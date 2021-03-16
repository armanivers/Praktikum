#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <ostream>

template<class T>
class Vector
{
    private:
    int d;
    T* m;

    public:
    Vector(int d);
    Vector(const Vector<T>& o);
    ~Vector();

    void set(int i, T key);

    T operator[](int i);
    
    // falls mit friend und hier in der klasse stehend, muss fur Vektorparemeter neues template U benutzt werden??
    // alternative: zeile 24 und 25 auskomentiere, und getter/setter nutzen
    // dritte alternative ist direkt hier bei der deklaration (zeile 26) implementieren mit {..} und template T nutzen als Parameter (zeile 25 weg!)
    template <class U>
    friend std::ostream& operator<<(std::ostream& o, const Vector<U>& v);

    // alternative mit getter/setter falls nicht friend
    inline int getD() const {return d;}
    inline T* getM() const {return m;}
};
#endif

template <class T>
Vector<T>::Vector(int d) : d{d}, m{new T[d]} {}

template <class T>
Vector<T>::Vector(const Vector<T>& o)
{
    for(int i = 0 ; i<o.d; i++)
    {
        set(i,o.m[i]);
    }
}

template <class T>
Vector<T>::~Vector()
{
    delete[] m;
}

template <class T>
void Vector<T>::set(int i, T key)
{
    m[i] = key;
}

template <class T>
T Vector<T>::operator[](int i)
{
    //if(i < 0 || i > d) throw std::out_of_range("error");

    return m[i];
}

template <class U>
std::ostream& operator<<(std::ostream& o, const Vector<U>& v)
{
    o << "(";
    for(int i = 0; i < v.d; i++)
    {
        o << v.m[i];
        if(i < v.d-1) 
        {
            o << "|";
        }
    }
    o << ")";
    return o;
}