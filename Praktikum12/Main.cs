using System;

namespace Praktikum12
{
    // delegates sind Methodenschablonen!
    // c# hat schon eine Methodenschablone fuer eine Generische void Methode <T> die auch ein Arguemnt von Typ T erwartet
    // diese heisst Action, also kann man statt diese sehr generische Methode einfach Action nutzen
    // ist sehr generisch (void und erwartet t) = Action in c#
    public delegate void myDelType<T>(T data);
    class Program
    {
        public static void WorkMethode(Auto data)
        {
            Console.WriteLine(data);
        }
        static void Main(string[] args)
        {
            Fuhrpark park = new Fuhrpark();

            for(int i = 0; i < 10; i++)
            {
                park.Aufnehmen(new Auto("Auto"+i,1990+i));
            }
            
            Console.WriteLine("Inventur:");

            // normale delegate Implementierung mit einer fertigen Methode
            park.InventurDelegate(WorkMethode);

            // Implementierung mit Lambda
            //park.InventurDelegate(a => Console.WriteLine(a));

            // mit ein Action statt delegate, da sehr generisch
            //park.InventurDelegateAction(a => Console.WriteLine(a));
            
            Console.Write("Flottenalter = "+park.BerechneFlottenalter());
            
            /*
            LinkedList<int> zahlen = new LinkedList<int>();
            for(int i = 0; i < 10; i++)
            {
                zahlen.Add(i);
            }

            zahlen.VisitAllDelegate(a => Console.WriteLine("Zahl ist "+a));
            */
        }
    }
}
