using Fh.Pk2.Devices;

namespace Fh.Pk2.Commands
{
    class CdStop : Command
    {
        CdPlayer player;

        public CdStop(CdPlayer player)
        {
            this.player = player;
        }
        public override void Execute()
        {
            player.Stop();
        }
    }   
}