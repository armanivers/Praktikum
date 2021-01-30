using Interface.Fh.Pk2.Devices;

namespace Interface.Fh.Pk2.Commands
{
    class CdStop : ICommand
    {
        CdPlayer player;

        public CdStop(CdPlayer player)
        {
            this.player = player;
        }
        public void Execute()
        {
            player.Stop();
        }
    }   
}