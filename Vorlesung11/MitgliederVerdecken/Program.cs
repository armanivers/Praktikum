using System;

namespace MitgliederVerdecken
{
    class A 
    {
        protected string text = "ich bin a";
        
        public void Methode1() {Console.WriteLine(text);}
        public virtual void Methode2() {Console.WriteLine(text);}
    }

    class B : A
    {
        public new string text = "ich bin b";
        public new void Methode1()
        {
            Console.WriteLine(text);
            Console.WriteLine("Meine basisklasse sagt: "+base.text);
        }

        public new void Methode2() {Console.WriteLine(text);}
    }
    class Program
    {
        static void Main(string[] args)
        {
            A a;
            B b = new B();
            a = b;

            b.Methode1(); // ich bin b, Meine Basisklasse sagt "ich bin a"
            b.Methode2(); // ich bin b

            a.Methode1(); // ich bin a
            a.Methode2(); // ich bin a
            
            // dynamische Bindung!
        }
    }
}
