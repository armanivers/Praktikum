using System;
using System.Threading;

namespace DelegatesTest
{
    class Timer
    {
        private bool run;
        private Thread zeitThread;
        public delegate void ZeitEreignisHandler(object sender,EventArgs arg);
        public event ZeitEreignisHandler ZeitEreignis;
        public Timer()
        {
            run = false;
        }
        public void Start()
        {
            if (!run)
            {
                run = true;
                zeitThread = new Thread(SekundenTakt);
                zeitThread.Start();
            }
        }
        public void Stopp()
        {
            if (run)
            {
                run = false;
            }
        }
        public void SekundenTakt()
        {
            while (run)
            {
                Thread.Sleep(1000);
                
                // Pruefen ob sich jemand registriert hat!
                if(ZeitEreignis != null) ZeitEreignis(this, null);
            }
        }
    }
}
