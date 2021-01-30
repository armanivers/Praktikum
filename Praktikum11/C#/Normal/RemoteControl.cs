using System;
using Fh.Pk2.Commands;

namespace Fh.Pk2.Rc
{
    class RemoteControl
    {
        private Command[,] devices;
        // normalerweise private Command[][]
        private const int MAX_DEVICES = 4; // 4 buttons
        private const int DEVICE_STATES = 2; // on/off
        public RemoteControl()
        {
            devices = new Command[MAX_DEVICES,DEVICE_STATES];
        }
        public void SetCommand(int i, Command on, Command off)
        {
            Console.WriteLine("Device Registered!");
            devices[i,0] = on;
            devices[i,1] = off;
        }

        public void PressOn(int i)
        {
            Console.WriteLine("On button pressed");
            // execute von CdStart? oder Start/stopp von CdPlayer
            devices[i,0].Execute();
        }

        public void PressOff(int i)
        {
            Console.WriteLine("Off button pressed");
            devices[i,1].Execute();
        }
    }
}