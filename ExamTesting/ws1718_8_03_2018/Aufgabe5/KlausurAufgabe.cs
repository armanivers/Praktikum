using System;

namespace Aufgabe5
{
    public delegate void statusChanged(string msg);
    class DiagnoseAdapter
    {
        public event statusChanged Meldung;

        public void CreateTestFehler()
        {
            MeldeFehler("Es ist ein Fehler aufgetreten, Achtung!");
        }
        public void MeldeFehler(string msg)
        {
            if(Meldung != null)
            {
                Meldung(msg);
            }
        }
       
    }

    class CarDisplay
    {
        public CarDisplay(DiagnoseAdapter dp)
        {
            dp.Meldung += StatusChange;
        }
        
        public void StatusChange(string msg)
        {
            Console.WriteLine(msg);
        }
    }
}
