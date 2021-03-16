#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

namespace fh_do
{
    template <class T>
    class Vector
    {
        private:
        int n;
        T *m;

        public:
        Vector(int n);
        Vector(const Vector& orig);
        ~Vector();

        inline int getN() const { return n; }
        inline T* getM() const { return m; }
        
        Vector<T> operator*(double skalar);
        
        
        // Implementierung als friend Funktion, dadurch getM() und getN() nicht notwendig
        friend std::ostream& operator<<(std::ostream& ausgabe, const Vector<T>& v)
        {
            for(int i = 0; i < v.n; i++)
            {
                ausgabe << v.m[i] << std::endl;
            }
            return ausgabe;
        }

        void set(int p, T key);

    };

    template <class T>
    Vector<T>::Vector(int n) : n{n}, m{new T[n]} {}
    
    template<class T>
    Vector<T>::Vector(const Vector<T>& orig) : Vector(orig.n)
    {
        for(int i = 0 ; i < orig.getN(); i++)
        {
            m[i] = orig.getM()[i]; 
        }
    }

    template <class T>
    Vector<T>::~Vector()
    {
        delete[] m;
    }

    template <class T>
    void Vector<T>::set(int p, T key)
    {
        m[p] = key;
    }

    
    template <class T>
    Vector<T> Vector<T>::operator*(double skalar)
    {
        Vector<T> result(n);
        for(int i = 0; i < n; i++)
        {
            result.getM()[i] = m[i] * skalar;
        }
        return result;
    }
    

    /*
    template <class T>
    std::ostream& Vector<T>::operator<<(std::ostream& ausgabe, const Vector<T>& v)
    {
        for(int i = 0; i < v.n; i++)
        {
            ausgabe << v.m[i] << std::endl;
        }

        return ausgabe;
    }
    */
}
#endif