#ifndef _REMOTECONTROL_H_
#define _REMOTECONTROL_H_

#include "command.h"

// in c++ "." (punkt) nicht erlaubt in namespace?
namespace fh_pk_rc{
    class RemoteControl
    {
        private:
        // statt die "4" hier zu definieren, geht es diese leer zu lassen und spater im konstruktor mit new[size][size]?
        // wie matrix mit ** zeiger
        fh_pk_commands::Command *devices[4][4];

        public:
        RemoteControl();
        void setComand();
        void pressOn();
        void pressOff();
    };
}

#endif