using System;

namespace MethodenMitReferenzen
{
    class Program
    { 
        // Methoden mit "call by reference"
        static void Inc(ref int i)
        {
            i++;
        }

        static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        // Methode mit "out" statt "ref"
        static void Init(out int value)
        {
            value = 100;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Start");
            
            int c = 1;
            Console.WriteLine("C = {0}",c);
            Inc(ref c);
            Console.WriteLine("C = {0}",c);
            
            int k = 29; int j = 99;
            Console.WriteLine("Swap test, a = {0} b = {1}",k,j);
            Swap(ref k,ref j);
            Console.WriteLine("Swap test, a = {0} b = {1}",k,j);
            
            // eine Methode mit "out" weisst einem Parameter einen Wert zu
            // hier muss newNumber NICHT initialisiert werden, also "int newNumber;" reicht! 
            int newNumber = 0;
            Console.WriteLine("Number now is {0}",newNumber);
            Init(out newNumber);
            Console.WriteLine("Number now is {0}",newNumber);            

            Console.WriteLine("End");
        }
    }
}
