#include <cstdlib>
#include "linkedlist.h"
#include <iostream>
#include <string.h>

LinkedList::LinkedList()
{
    start = nullptr;
    end = nullptr;
    size = 0;
}

int LinkedList::append(const char* text)
{
    // mit free(node) -> kein destruktoraufruf, nur speicher loeschen
    // deswegen delete(node) und Element mit new statt malloc erzeugen

    Node *node = new Node();
    //Node *node = (Node*) malloc(sizeof(Node));

    if(node == nullptr) return 0;
    
    node->text = text;
    size++;

    // keine Elemente
    if(start == nullptr)
    {
        start = end = node;
        return 1;
    }

    node->prev = end;
    end->next = node;
    end = node;
    return 1;
}

int LinkedList::insert(const char* text, int p)
{
    if(p >= size) return append(text);

    Node *newNode = new Node();
    //Node *newNode = (Node*) malloc(sizeof(Node));
    
    if(newNode == nullptr) return 0;

    newNode->text = text;
    Node *temp = start;

    // am Anfang einfuegen
    if(p == 0)
    {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
        size++;
        return 1;
    }

    int counter = 0;

    while(temp != nullptr)
    {
        if(counter == p)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }
    
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev->next = newNode;
    temp->prev = newNode;

    size++;
    return 1;
}

int LinkedList::remove(int p)
{
    if(p < 0) return -1;
    
    Node *temp = start;

    // Am Anfang loeschen
    if(p == 0)
    {
        start = start->next;
        start->prev = nullptr;
        delete(temp);
        size--;
        return 1;
    }
    // Am Ende loeschen
    if(p >= size-1)
    {
        temp = end;
        end = end->prev;
        end->next = nullptr;
        delete(temp);
        size--;
        return 1;
    }

    int counter = 0;
    while(temp != nullptr)
    {
        if(counter == p)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete(temp);
    size--;

    return 1;
}

const char* LinkedList::get(int p)
{
     if(size == 0 || p > size || p < 0)
     {
         return nullptr;
     }

    
    Node *temp = start;
    int counter = 0;

    while(temp != nullptr)
    {
        if(counter == p)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }
    return temp->text;
}

int LinkedList::index_of(const char *text)
{
    if(size == 0) return -1;

    Node *temp = start;

    int index = 0;

    while(temp != nullptr)
    {
        // strcmp wie compareTo aus java, liefert -1,0,1 deswegen wenn strings gleich sind, kommt 0 -> "false" in c++
        if(strcmp(temp->text,text) == 0)
        {
            return index;
        }

        index++;
        temp = temp->next;
    } 

    return -1;
}

const char* LinkedList::first()
{
    if(start == nullptr) return nullptr;
    return start->text;
}

const char* LinkedList::last()
{
    if(end == nullptr) return nullptr;
    return end->text;
}

void LinkedList::visit_all(void (*work) (const char* t))
{
    Node *temp = start;

    while(temp!=nullptr)
    {
        work(temp->text);
        temp = temp->next;
    }
}
