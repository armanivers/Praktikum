using System;
using Fh.Pk2.Devices;
using Fh.Pk2.Rc;
using Fh.Pk2.Commands;

namespace Praktikum11
{
    class Program
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
