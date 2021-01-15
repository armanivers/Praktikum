#include "bild.h"

Bild::Bild(std::string titel, int jahr, std::string ort) : Medium(titel, jahr), ort{ort} {}

void Bild::druckeDaten()
{
    std::cout  << "ID = " << getId() << " \"" << getTitel() <<  "\"" << " aufgenommen in " << getJahr() << " in Jahr " << ort << std::endl;
}