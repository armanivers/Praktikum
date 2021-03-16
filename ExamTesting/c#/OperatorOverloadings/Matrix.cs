using Microsoft.VisualBasic.CompilerServices;
using System;

namespace OperatorOverloadings
{
    class Matrix<T> where T : struct
    {
        private int n;
        public int Dimension{get => n;}
        private T[,] mat;
        // Multidimensional Indexer
        public T this[int index1, int index2]
        {
            get
            {
                return mat[index1,index2];
            }
            set
            {
                mat[index1,index2] = value;
            }
        }

        public Matrix(int n)
        {
            this.n = n;
            mat = new T[n,n];
        }

        public void Set(int x, int y,T key)
        {
            mat[x,y] = key;
        }

        public static Matrix<T> operator*(Matrix<T> a, Matrix<T> b)
        {
            if(a.Dimension != b.Dimension) throw new MatrixException("Matrix Dimensions have to be the same!");
            
            int dim = a.Dimension;

            Matrix<T> result = new Matrix<T>(dim);

            for(int i = 0; i < dim ;i++)
            {
                for(int j = 0; j < dim; j++)
                {
                    for(int k = 0; k < dim; k++)
                    {
                        // dynamic nutzen, weil a[i,k] ist von Typ T, und * Operator vielleicht nicht fur T vorhanden, soll dynamisch geguckt werden 
                        result[i,j] += (dynamic)a[i,k] * (dynamic)b[k,j];
                    }
                }
            }
            return result;
        }

        public static Matrix<T> operator+(Matrix<T> a, Matrix<T> b)
        {
            int dim = a.Dimension;
            Matrix<T> result = new Matrix<T>(dim);

            for(int i = 0; i < dim ;i++)
            {
                for(int j = 0; j < dim; j++)
                {
                    result[i,j] = (dynamic)a[i,j] + (dynamic)b[i,j];
                }
            }
            return result;
        }

        // "Ausgabeoperator" (Console.WriteLine()) nutzt toString!
        public override string ToString()
        {
            string result = "";
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    result+= mat[i,j]+" ";
                }
                result += "\n";
            }
            return result;
        }

        // operatoren == und != mussen paarweise uberladen werden (d.h. Implementierung fur beide notwendig), gilt auch fur >,< und >=, <=
        public static bool operator==(Matrix<T> a, Matrix<T> b)
        {
            if(a.Dimension != b.Dimension) return false;

            for(int i = 0; i < a.Dimension; i++)
            {
                for(int j = 0; j < a.Dimension; j++)
                {
                    if((dynamic)a[i,j] != (dynamic)b[i,j]) return false;
                }
            }
            return true;
        }
        public static bool operator!=(Matrix<T> a, Matrix<T> b)
        {
            return !(a==b);
        }

        public static Matrix<T> operator-(Matrix<T> a)
        {
            for(int i = 0; i < a.Dimension; i++)
            {
                for(int j = 0; j < a.Dimension; j++)
                {
                    a[i,j]=(dynamic)a[i,j]*-1;
                }
            }
            return a;
        }
    }
}
