#ifndef _CDSTART_H_
#define _CDSTART_H_

#include "command.h"
#include "cdplayer.h"

namespace fh_pk_commands
{
    class CdStart : Command
    {
        private:
        fh_pk2_devices::CdPlayer player;
        public:
        override void execute();
    };
}
#endif