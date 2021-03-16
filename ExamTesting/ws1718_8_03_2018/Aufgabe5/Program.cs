using System;

namespace Aufgabe5
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start!");

            DiagnoseAdapter dp = new DiagnoseAdapter();
            CarDisplay cd = new CarDisplay(dp);

            dp.CreateTestFehler();

            Console.WriteLine("Ende!");
        }
    }
}
