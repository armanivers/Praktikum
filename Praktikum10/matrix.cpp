#include "matrix.h"

Matrix<T>::Marix(int n) : n{n}
{
    *m = new int[n];
    **m = new int[n];
}

Matrix<T>::~Matrix()
{

}

Matrix<T>::Matrix(const Matrix &orig)
{

}

void Matrix<T>::set(int zeile, int spalte, int zahl)
{

}