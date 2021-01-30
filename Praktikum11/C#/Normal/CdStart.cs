using Fh.Pk2.Devices;

namespace Fh.Pk2.Commands
{
    class CdStart : Command
    {
        CdPlayer player;

        public CdStart(CdPlayer player)
        {
            this.player = player;
        }
        public override void Execute()
        {
            player.Start();
        }
    }   
}