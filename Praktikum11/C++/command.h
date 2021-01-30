#ifndef _COMMAND_H_
#define _COMMAND_H_

namespace fh_pk_commands{
    class Command
    {
        public:
        virtual void execute() = 0;    
    };
}
#endif