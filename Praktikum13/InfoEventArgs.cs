using System;
namespace Praktikum13
{
    public class InfoEventArgs : EventArgs
    {
        public readonly string hersteller;
        public readonly int baujahr;
        public InfoEventArgs(string hersteller, int baujahr)
        {
            this.hersteller = hersteller;
            this.baujahr = baujahr;
        }
    }
    
}