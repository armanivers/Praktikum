using System;

namespace Praktikum12
{
    public class Fuhrpark
    {
        private LinkedList<Auto> autos;
        public Fuhrpark()
        {
            autos = new LinkedList<Auto>();
        }

        public void Aufnehmen(Auto a)
        {
            autos.Add(a);
        }

        public void Inventur()
        {
            /* IEnumerator nicht implementiert
            foreach(Auto a in autos)
            {
                a.ToString();
            }
            */

            I_Iterator<Auto> iterator = autos.Iterator();

            while(iterator.HasNext())
            {
                Console.WriteLine(iterator.Next().ToString());
            }
        }
        public void InventurDelegate(myDelType<Auto> Work)
        {
            I_Iterator<Auto> iterator = autos.Iterator();

            while(iterator.HasNext())
            {
                Work(iterator.Next());
            }
        }

        // siehe main.cs -> die delegate Methodenschablone void x<T> (T input) ist sehr genersich
        // in c# kann dies durch Action<T> erstzt werden, Resultat ist gleich, man spart sich das Delegate in Main
        public void InventurDelegateAction(Action<Auto> Work)
        {
            I_Iterator<Auto> iterator = autos.Iterator();

            while(iterator.HasNext())
            {
                Work(iterator.Next());
            }
        }
        // Func (angucken) !! Erwartet 2 Generischte Typen, zweites Argument ist ein "return", eine Art Erweiterung von Action (delegate void Schablone)
        /*
        public void InventurDelegateFunc(Action<Auto> Work)
        {
            I_Iterator<Auto> iterator = autos.Iterator();

            while(iterator.HasNext())
            {
                Work(iterator.Next());
            }
        }
        */
        public double BerechneFlottenalter()
        {
            double durschnitt = 0;
            
            /* IEnumerator nicht implementiert
            foreach(Auto a in autos)
            {
                durschnitt +=a.Baujahr;
            }
            */

            I_Iterator<Auto> iterator = autos.Iterator();
            
            while(iterator.HasNext())
            {
                durschnitt+=iterator.Next().Baujahr;
            }
            return durschnitt/autos.Size;
        }
    }
}