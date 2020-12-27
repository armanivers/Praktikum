#include "medium.h"
#include "audio.h"
#include "bild.h"

// lieber in CPP Datei implementieren!
//int Medium::counter = 0;

int main()
{
    Audio *a = new Audio("It Means Nothing",2007,"Stereophonics",229);
    a->druckeDaten();
    Bild *b = new Bild("Gebaeude FB Informatik",2018,"Dortmund");
    b->druckeDaten();
    
    Medium *medien[2];
    medien[0] = a;
    medien[1] = b;
    
    medien[0]->druckeDaten();
    medien[1]->druckeDaten();

    Audio audio("It Means Nothing",2007,"Stereophonics",229);
    audio.druckeDaten();
    Bild bild("Gebaeude FB Informatik",2018,"Dortmund");
    bild.druckeDaten();
    

    return 0;
}
