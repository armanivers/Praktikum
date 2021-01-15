#ifndef _AUDIO_H
#define _AUDIO_H
#include "medium.h"
class Audio : public Medium
{
    private:
    std::string interpret;
    int dauer;

    public:
    // Konstruktor nur so lassen, rest kommt in cpp
    Audio(std::string titel, int jahr, std::string interpret, int dauer);

    void druckeDaten() override;
};
#endif