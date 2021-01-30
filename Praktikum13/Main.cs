using System;

namespace Praktikum13
{
    class Program
    {
        static void Main(string[] args)
        {
            Fuhrpark park = new Fuhrpark();

            for(int i = 0; i < 10; i++)
            {
                park.Aufnehmen(new Auto("Auto"+i,1990+i));
            }
            
            Console.WriteLine("Inventur:");

            park.Inventur();

            Console.Write("Flottenalter = "+park.BerechneFlottenalter());
        }
    }
}
