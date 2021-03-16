using System.Linq.Expressions;
using System;

namespace OperatorOverloadings
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start!");

            Matrix<int> a = new Matrix<int>(2);
            a.Set(0,0,1);
            a.Set(0,1,2);
            a.Set(1,0,3);
            a.Set(1,1,4);

            Matrix<int> b = a;
            
            Console.WriteLine("Matrix a:");
            Console.WriteLine(a);

            Console.WriteLine("Matrix b:");
            Console.WriteLine(b);

            Console.WriteLine("+ Operator");
            Console.WriteLine(a+b);

            Console.WriteLine("== und != Operator");
            Console.WriteLine("== "+(a==b) + " != " +(a!=b));

            Console.WriteLine("Matix c:");
            Matrix<int> c = new Matrix<int>(4);

            Console.WriteLine("Exception Test a*c");
            
            try
            {
                Matrix<int> exceptionResult = a*c;

            }catch(MatrixException e)
            {
                Console.WriteLine("Exception! "+e.Message);
            }


            Console.WriteLine("End!");
        }
    }
}
