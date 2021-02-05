using System;

namespace Praktikum13
{
    public class FuhrparkEventArgs : EventArgs
    {
        public string hersteller;
        public string Hersteller
        {
            get { return hersteller;}
            set { hersteller = value;}
        }
        // Soll eine Automatische Property sein
        // Vorteile dadruch: da kein setter, ist es automatisch nur readonly!
        public int Baujahr {get;}
        
        public FuhrparkEventArgs(string hersteller, int baujahr)
        {
            this.hersteller = hersteller;
            this.Baujahr = baujahr;
        }

        public FuhrparkEventArgs(Auto a)
        {
            this.hersteller = a.Hersteller;
            this.Baujahr = a.Baujahr;
        }
    }
    
}