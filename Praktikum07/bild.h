#ifndef _BILD_H
#define _BILD_H
#include "medium.h"

class Bild : public Medium {
    private:
    std::string ort;

    public:
    Bild(std::string titel, int jahr, std::string ort);

    void druckeDaten() override;
};
#endif
