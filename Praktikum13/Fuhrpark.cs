using System;

namespace Praktikum13
{
    public delegate void myDelType(object sender, FuhrparkEventArgs args);
    public class Fuhrpark
    {
        // Vorteil durch Event + Delegate: mann kann den Sender spezifizieren (z.B. Auto)
        public event myDelType AutoAufgenommen;

        // mann kann sich die Delegate Schablone ersparen, indem man einen Eventhandler nutzt
        // hier werden die EventArgs spezifiziert und delegate+event als schablone verwendet
        
        //public event EventHandler<FuhrparkEventArgs> AutoAufgenommenEventHandler;

        private LinkedList<Auto> autos;
        public Fuhrpark()
        {
            autos = new LinkedList<Auto>();
        }

        public void Aufnehmen(Auto a)
        {
            autos.Add(a);
            // normales Delegate+Event Muster
            OnAutoAufgenommen(new FuhrparkEventArgs(a.Hersteller,a.Baujahr));
            
            // Eventhandler Alternative
            //OnAutoAufgenommenEventHandler(new FuhrparkEventArgs(a));

            // Kurze Eventhandler Alternative
            //OnAutoAufgenommenEventHandlerKurz(a);
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

        public void OnAutoAufgenommen(FuhrparkEventArgs args)
        {
            // handler (Autoaufgenommen) darf nicht null sein! (also keine registrierte subscriber)
            // deswegen zuerst pruefen ob null
            var handler = AutoAufgenommen;

            if(handler != null)
            {
                handler(this,args);
            }
        }


        // hier als Argugment jedoch args
        public void OnAutoAufgenommenEventHandler(FuhrparkEventArgs args)
        {
            // falls mit eventhandler, muss man mit Invoke arbeiten und auch nach null referenz pruefen!
            AutoAufgenommenEventHandler?.Invoke(this,args);
        }

        // eventhandler alternative alles kurz gemacht
        // Argument ist nur ein Auto Objekt, eventargs wird automatisch erstellt
        public void OnAutoAufgenommenEventHandlerKurz(Auto auto) => AutoAufgenommenEventHandler?.Invoke(this, new FuhrparkEventArgs(auto));
    }
}