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
    //Node* node = new Node();
    Node *node = (Node*) malloc(sizeof(Node));

    if(node == nullptr) return 0;
    
    node->text = text;
    size++;

    // keine Elemente
    if(start == nullptr && end == nullptr)
    {
        start = end = node;
        return 1;
    }

    // nur 1 Element
    if(start == end)
    {
        start->next = node;
        end = node;
        return 1;
    }

    node->prev = end;
    end->next = node;
    end = node;
    return 1;
}

int LinkedList::insert(const char* text, int p)
{
    if(p >= size) append(text);

    //Node* newNode = new Node();
    Node *newNode = (Node*) malloc(sizeof(Node));
    
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

    while(temp->next != nullptr)
    {
        //std::cout << temp->text << " counter:" << counter << std::endl;
        if(counter == p)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }
    
    //std::cout <<  std::endl <<"temp text = " << temp->text << " temp prev " << temp->prev->text << " temp next " << temp->next->text<< std::endl;

    //Node *temp = temp->next;
    
    // [a] [NEW] [b] [c]
    //           tmp

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
    
    Node *temp ;

    if(p == 0)
    {
        temp = start;
        start = start->next;
        delete(temp);
        size--;
        return 1;
    }

    if(p >= size)
    {
        temp = end;
        end = end->prev;
        delete(temp);
        size--;
        return 1;
    }

    int counter = 0;
    while(temp-> next != nullptr)
    {
        if(counter == p)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }


    // kein Nachfolger
    if(temp->next == nullptr)
    {
        temp->prev = nullptr;
        delete(temp);
        size--;
        return 1;
    }

    // hat Nachfolger

    temp->prev->next = temp->next;
    temp->prev = temp->prev;

    delete(temp);
    size--;
    return 1;

}

const char* LinkedList::get(int p)
{
     if(size == 0 || p > size || p < 0)
     {
         return "";
     }

    
    Node *temp = start;
    int counter = 0;

    while(temp->next != nullptr)
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

    int counter = 0;

    while(temp->next != nullptr)
    {
        // temp->text == text (ging am anfang??)
        if(strcmp(temp->text,text))
        {
            return counter;
        }
        counter++;
        temp = temp->next;
    } 

    return -1;
}

const char* LinkedList::first()
{
    if(start == nullptr) return "";
    return start->text;
}

const char* LinkedList::last()
{
    if(end == nullptr) return "";
    return end->text;
}

void LinkedList::visit_all(void (*work) (const char* t))
{
    Node *temp = start;

    while(temp->next != nullptr)
    {
        work(temp->text);
        temp = temp->next;
    }
    work(temp->text);
}
