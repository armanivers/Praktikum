#include "bild.h"

Bild::Bild(std::string titel, int jahr, std::string ort) : Medium(titel, jahr), ort{ort} {}

void Bild::druckeDaten()
{
    Medium::druckeDaten();
    std::cout << " aufgenommen in " << getJahr() << " in Jahr " << ort << std::endl;
}