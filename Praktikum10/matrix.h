#ifndef _MATRIX_H
#define _MATRIX_H
#include <iostream>

namespace fhdo_pk2{

        template<class T>
        class Matrix{
        
        private:
        int n;
        T **m;

        public:
        Matrix(int n);
        ~Matrix();
        Matrix(const Matrix& orig);

        void set(int zeile, int spalte,T zahl);

        void initZero();

        // Operatoren
        // braucht man das nicht?
        //Matrix<T> operator*(const Matrix<T> &m1,const Matrix<T> &m2);
        

        // muss const sein!
        T* operator[](int index) const
        {
            if(index < 0 || index > this->getDimension())
            {
                return nullptr;
            }

            return m[index];
        }

        // Getter/Setter

        // warum muss das unbedingt const sein? (sonst Fehler bei operator* wo ich getDimension() Aufrufe)
        inline int getDimension() const
        {
            return n;
        }

        inline T* getMatrix(int zeile) const
        {
            return m[zeile];
        }
    };

    template<class T>
    Matrix<T>::Matrix(int n) : n{n}
    {   
        std::cout << "Konstruktor" << std::endl;
        // Zeile
        // M zeigt auf ein T Zeiger Array
        // das T* braucht man, weil m immernoch ein doppelzeiger ist, und T nur ein Zeiger (Konvertierung von ** zu *)
        m = new T*[n];

        // Spalte
        // m[i] ist eigentlich m*
        for(int i = 0; i < n ; i++)
        {
            m[i] = new T[n];
        }

        // Matrix zahlen auf 0 setzen;
        initZero();
    }

    // Hilfsmethode um Matrix mit 0 initialisieren
    template<class T>
    void Matrix<T>::initZero()
    {
        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
            {
                m[z][s] = 0;
            }
        }
    }

    template<class T>
    Matrix<T>::~Matrix()
    {
        std::cout << "Destruktor" << std::endl;
        for(int i = 0; i < n ; i++)
        {
            delete[](m[i]);
        }
        // fur arrays delete[] nutzen
        delete[](m);
    }

    // : Matrix(orig.getDimension()) oder :Matrix(n)
    template<class T>
    Matrix<T>::Matrix(const Matrix& orig) : Matrix(orig.getDimension())
    {
        std::cout << "Copy Konstruktor" << std::endl;

        int dimension = orig.getDimension();

        for(int z = 0; z < dimension; z++)
        {
            for(int s = 0; s < dimension; s++)
            {
                // copy konstruktor nutzt referenzen (also immer orig.ATTRIBUT (mit PUNKT))
                this->set(z,s,orig.m[z][s]);
            }       
        }
    }

    template<class T>
    void Matrix<T>::set(int zeile, int spalte,T zahl)
    {
        m[zeile][spalte] = zahl;
    }


    // kommt kein Matrix<T> Matrix<T>:: vorne?
    template<class T>
    Matrix<T> operator*(const Matrix<T> &m1,const Matrix<T> &m2)
    {

        if (m1.getDimension() != m2.getDimension())
        {
            // do something? return zero matrix?
        }

        int n = m1.getDimension();

        Matrix<T> result(n);

        for(int z = 0; z < n ; z++)
        {
            for(int s = 0; s < n; s++)
            {
                // Falls Matrix nicht mit 0 initialisiert!
                //result[z][s] = 0;

                // Alternative ohne Uberladung von []
                //result.getMatrix(z)[s] = 0;
                for(int i = 0; i < n; i++)
                {
                    result[z][s] += m1[z][i] * m2[i][s];
                    
                    // Alternative ohne Uberladung von []
                    //result.getMatrix(z)[s] += m1.getMatrix(z)[i] * m2.getMatrix(i)[s];
                }
            }
        }

        return result;        
    }

    template<class T>
    std::ostream& operator<<(std::ostream& ausgabe, const Matrix<T>& m)
    {
        int n = m.getDimension();

        for(int z = 0; z < n; z++)
        {
            ausgabe << "|";
            for(int s = 0; s < n; s++)
            {
                ausgabe << m[z][s] << " ";

                // Alternative ohne Uberladung von []
                //ausgabe << m.getMatrix(z)[s] << " ";
            }
            ausgabe << "|" <<std::endl;
        }

        return ausgabe;
    }

    template<class T>
    Matrix<T> operator+(const Matrix<T> &m1,const Matrix<T> &m2)
    {
        if(m1.getDimension() != m2.getDimension())
        {
            // return zero matrix
        }

        int n = m1.getDimension();

        Matrix<T> result(n);

        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
            {
                result[z][s] = m1[z][s] + m2[z][s];
            }
        }

        return result;
    }

    template<class T>
    Matrix<T> operator-(const Matrix<T> &m1, const Matrix<T> &m2)
    {
        if(m1.getDimension() != m2.getDimension())
        {
            // return zero matrix
        }

        int n = m1.getDimension();

        Matrix<T> result(n);

        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
            {
                result[z][s] = m1[z][s] - m2[z][s];
            }
        }

        return result;
    }

    
    template<class T>
    Matrix<T> operator^(Matrix<T> &m,int number)
    {
        if(number < 0) return m;

        // return zero matrix;
        if(number == 0) return Matrix<T> (m.getDimension());

        int n = m.getDimension();

        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
            {
                // power of 
                for(int i = 0; i < number-1; i++)
                {
                     m[z][s] *=m[z][s];
                }
            }
        }

        return m;
    }
    

    template<class T>
    bool operator==(const Matrix<T> &m1, const Matrix<T> &m2)
    {
        if(m1.getDimension() != m2.getDimension())
        {
            return false;
        }

        int n = m1.getDimension();

        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
                {
                    if(m1[z][s] != m2[z][s])
                    {
                        return false;
                    }
                }   
        }
        return true;
    }

    template<class T>
    Matrix<T> operator-(Matrix<T> &m)
    {
        int n = m.getDimension();

        for(int z = 0; z < n; z++)
        {
            for(int s = 0; s < n; s++)
            {
                m[z][s] *= -1;
            }   
        }
    
        return m;
    }
    
}
#endif