using System;
using Interface.Fh.Pk2.Devices;
using Interface.Fh.Pk2.Rc;
using Interface.Fh.Pk2.Commands;

namespace Interface.Praktikum11
{
    class HauptProgramm
    {
        static void Main(string[] args)
        {
            // dotnet create console und dotnet run

            Console.WriteLine("Start");

            RemoteControl remote = new RemoteControl();
            CdPlayer player = new CdPlayer();
            
            remote.SetCommand(0,new CdStart(player),new CdStop(player));

            remote.PressOn(0);
            remote.PressOff(0);

            Console.WriteLine("Stop");
        }
    }
}
