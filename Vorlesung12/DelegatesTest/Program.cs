using System;
using System.Threading;
namespace DelegatesTest
{
    class Program
    {
        public static void SayHello(string name)
        {
            Console.WriteLine("Hello " +name);
        }

        public static void SayHallo(string name)
        {
            Console.WriteLine("Hallo "+name);
        }
        // Normales Delegate
        public delegate void Greetings(string name);

        // Anomyme Delegate Methode
        public delegate void Anonym(string name);
        static void Main(string[] args)
        {
            Console.WriteLine("Start");

            Greetings g = new Greetings(SayHello);
            g("Ari");
            
            g += SayHallo;
            g("Ari");

            // Anonym, d.h. direkt mit eine Methodenimplementierung
            Anonym a = delegate(string name) {
                Console.WriteLine("Ich bin Anonym " +name);
            };

            a("Anonymous");

            Timer t = new Timer();
            t.Start();
            CounterUp u = new CounterUp(t);
            // Warten Simulieren
            Thread.Sleep(10000);
            t.Stopp();

            Console.WriteLine("End");
        }
    }
}

