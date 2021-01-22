#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "iterator.h"
#include "iostream"

namespace fhdo_pk2{

template <class T>
class LinkedList{

    private:
    class Node{
        public:
        Node *next;
        Node *prev;
        T text;
        Node(){
            next = nullptr;
            prev = nullptr;
            text = nullptr;
        }
    };
    
    class ListIterator: public Iterator<T>{
        private:
        Node *element;

        public:
        ListIterator(Node* element): element{element}{}
        bool hasNext() override;
        T next() override;
    };

    Node *start;
    Node *end;

    public:
    int size;

    LinkedList();
    LinkedList(const LinkedList& orig);
    ~LinkedList();

    int append(const T text);
    int insert(const T text, int p);
    int remove(int p);
    T get(int p);
    int index_of(T text);
    T first();
    T last();
    void visit_all(void (*work)(T t));

    Iterator<T>* iterator();
};


template<class T>
LinkedList<T>::LinkedList()
{
    std::cout << "Konstruktor" << std::endl;
    start = nullptr;
    end = nullptr;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& orig):LinkedList()
{
    Node *n = orig.start;
    while(n != nullptr)
    {
        this->append(n->text);
        n = n->next;
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    std::cout << "Destructor" << std::endl;
    while(remove(0));
}

template<class T>
int LinkedList<T>::append(T text)
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

template<class T>
int LinkedList<T>::insert(T text, int p)
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

template<class T>
int LinkedList<T>::remove(int p)
{
    if(p < 0 || start == nullptr) return 0;
    
    Node *temp = start;

    // Am Anfang loeschen
    if(p == 0)
    {
        start = start->next;

        if(start != nullptr)
        {
            start->prev = nullptr;
        }
        else
        {
            start = end = nullptr;
        }
        
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

template<class T>
T LinkedList<T>::get(int p)
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

template<class T>
int LinkedList<T>::index_of(T text)
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

template<class T>
T LinkedList<T>::first()
{
    if(start == nullptr) return nullptr;
    return start->text;
}

template<class T>
T LinkedList<T>::last()
{
    if(end == nullptr) return nullptr;
    return end->text;
}

// Iteratoren
template<class T>
Iterator<T>* LinkedList<T>::iterator()
{
    return new ListIterator(this->start); 
}

template<class T>
bool LinkedList<T>::ListIterator::hasNext()
{
    return (element != nullptr);
}

template<class T>
T LinkedList<T>::ListIterator::next()
{
    Node *temp = element;
    element = element->next;
    return temp->text;
}

template<class T>
void LinkedList<T>::visit_all(void (*work) (T t))
{
   Iterator<T>* it = iterator();

    while(it->hasNext())
    {
        work(it->next());
    }

    delete(it);
}

} // ende von namespace
#endif