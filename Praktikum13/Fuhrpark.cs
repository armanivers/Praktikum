using System;

namespace Praktikum13
{
    public class Fuhrpark
    {
        public event EventHandler<InfoEventArgs> NewCar;

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

        public void OnNewCar(InfoEventArgs e)
        {
            
        }
    }
}