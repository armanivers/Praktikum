#include "linkedlist.h"

#include <iostream>

#include "medium.h"
#include "audio.h"
#include "bild.h"

// print Methode an Template anpassen!
void print(Medium* t)
{
    t->druckeDaten();
}

int main()
{
    using namespace std;
    using namespace fhdo_pk2;

    cout << "Start" << endl;
    
    Audio* audio1 = new Audio("Audio_Name1",2010,"Interpret_Name1",3);
    Audio* audio2 = new Audio("Audio_Name2",2010,"Interpret_Name2",3);
    Bild bild1("Bild_Name1",2010,"Dortmund");
    Bild bild2("Bild_Name2",2010,"Dortmund");

    // dynamisch
    // LinkedList<Medium*> medien = new LinkedList<Medium*>();  
    // LinkedList<Medium> *medien = new LinkedList<Medium>();

    // statisch
    LinkedList<Medium*> medien;
    
    // Audio ist ein zeiger, append erwartet zeiger?
    medien.append(audio1);
    // bild kein Zeiger, deswegen muss man sich zuerst die Adresse holen
    medien.append(&bild1);


    medien.insert(audio2,1);
    medien.append(&bild2);


    medien.visit_all(print);

    // Elemente loeschen? (for schleife und remove(i)?)

    cout << "Ende" << endl;
    
    return 0;
}
