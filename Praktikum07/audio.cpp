#include <string>
#include "Audio.h"

// Konstruktor immer direkt in .h oder in cpp?

//Audio::Audio(std::string titel, int jahr, std::string interpret, int dauer) 
//: Medium(titel,jahr), interpret{interpret}, dauer{dauer}{}


// geht es hier mit base.druckeDaten() und in abstrakte klasse id,titel und jahr ausgeben?
// -> pure virtual haben KOENNEN methoden definition haben

void Audio::druckeDaten()
{
    Medium::druckeDaten();
    std::cout << " von " << interpret << " aus " << getJahr() <<" Spieldauer: " << dauer << " sek." << std::endl;
}