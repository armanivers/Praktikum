using System;

namespace DelegatesTest
{
    class CounterUp
    {
        private int count;
        public CounterUp(Timer t)
        {
            t.ZeitEreignis += ausgabe;
        }
        public void ausgabe(object sender, EventArgs args)
        {
            Console.WriteLine((count++) + " Sekunden seit Start");
        }
    }
}