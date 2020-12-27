#ifndef _AUDIO_H
#define _AUDIO_H
#include "medium.h"
class Audio : public Medium
{
    private:
    std::string interpret;
    int dauer;

    public:
    // hier : Medium(titel,jahr), interpret{interpret}, dauer{dauer}{} nach konstruktor schreiben?
    Audio(std::string titel, int jahr, std::string interpret, int dauer) : Medium(titel,jahr), interpret{interpret}, dauer{dauer}{}

    void druckeDaten() override;
};
#endif