#include <string>
#include "Audio.h"

// Konstruktor immer in .cpp implementieren!

Audio::Audio(std::string titel, int jahr, std::string interpret, int dauer) : Medium(titel,jahr), interpret{interpret}, dauer{dauer}{}

// pure virtual methoden habe keine implementierung! Deswegen geht Medium::druckeDate() nicht! (base. aufrufen)

void Audio::druckeDaten()
{
    std::cout << "ID = " << getId() << " \"" << getTitel() << "\"" << " von " << interpret << " aus " << getJahr() <<" Spieldauer: " << dauer << " sek." << std::endl;
}