using Interface.Fh.Pk2.Devices;

namespace Interface.Fh.Pk2.Commands
{
    class CdStart : ICommand
    {
        CdPlayer player;

        public CdStart(CdPlayer player)
        {
            this.player = player;
        }
        public void Execute()
        {
            player.Start();
        }
    }   
}