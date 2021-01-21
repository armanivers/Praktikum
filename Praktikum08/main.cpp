#include "linkedlist.h"
#include <iostream>

void print(const char* t)
{
    std::cout << t << std::endl;
}

int main()
{
    using namespace std;
    using namespace fhdo_pk2;

    cout << "Start" << endl;
    
    LinkedList liste;

    liste.append("Element 1");
    liste.insert("Element 2",2); 

    LinkedList liste2 = liste; 
    cout << "Liste:" << endl;
    
    liste.visit_all(print);
    liste.remove(2);
    
    cout << "Liste:" << endl;
    
    liste.visit_all(print); 
    
    cout << "Liste2:"<< endl;
    
    liste2.visit_all(print);

    cout <<"Ende"<< endl;

    return 0;
}
