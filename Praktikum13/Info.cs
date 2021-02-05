using System;

namespace Praktikum13
{
    // Alle aus dieser Klase gehort eigentlich in der Main.cs
    // Jedoch in praktikum13 soll man dies in eine externe Klasse "Info" lagern 
    public class Info
    {
        public Info(Fuhrpark park)
        {
            park.AutoAufgenommen += Ausgabe;
        }

        private void Ausgabe(object sender, FuhrparkEventArgs args)
        {
            Console.WriteLine("Delegate Info Klasse: Baujahr = {0}, Hersteller = {1}",args.Baujahr, args.hersteller);
        }
    }
}