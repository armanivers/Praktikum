#include "linkedlist.h"
#include <iostream>

void print(const char* t)
{
    std::cout << t << std::endl;
}

int main()
{
    // im Heap gespeichert
    LinkedList *list = new LinkedList();

    // auf Stack
    //LinkedList list;

    list->append("a");
    list->append("b");
    list->append("c");
    list->append("d");
    list->append("e");

    std::cout << "Anzahl Elemente: " << list->size << std::endl;
    std::cout << "Element erste Stelle: " << list->first() << std::endl;
    std::cout << "Element letzte Stelle: " << list->last() << std::endl;

    std::cout 
    << "pos[0]: " << list->get(0)
    << " pos[1]: " << list->get(1)
    << " pos[2]: " << list->get(2) 
    << std::endl;

    std::cout << "Position von Text [Element2]: " << list->index_of("Element2") << std::endl; 

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }
    std::cout << "------------------" << std::endl;
        
    std::cout << "Einfuegen von [0] and pos[0] ist " << list->insert("0",0) << std::endl;

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }

    std::cout << "------------------" << std::endl;
    
    std::cout << "Einfuegen von [1] and pos[1] ist " << list->insert("1",1) << std::endl;

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }

    std::cout << "------------------" << std::endl;
    
    std::cout << "Einfuegen von [3] and pos[3] ist " << list->insert("3",3) << std::endl;

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }
    std::cout << "------------------" << std::endl;
    std::cout << "Visit all test " << std::endl;
    list->visit_all(print);

    std::cout << "------------------" << std::endl;
    
    std::cout << "Loeschen von Element Pos[0] " << list->remove(0) << std::endl;
    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }

    std::cout << "Loeschen von Element Pos[1] " << list->remove(1) << std::endl;

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }

    std::cout << "Loeschen von Element Pos[3] " << list->remove(3) << std::endl;

    for(int i = 0; i < list->size; i++)
    {
        std::cout << "Pos: " << i << " = " << list->get(i) << std::endl; 
    }

    std::cout << "------------------" << std::endl;

    std::cout << "End of testing" << std::endl;

    return 0;
}
