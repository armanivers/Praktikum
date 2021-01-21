#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "iterator.h"

namespace fhdo_pk2{
class LinkedList{

    private:
    class Node{
        public:
        Node *next;
        Node *prev;
        const char *text;
        Node(){
            next = nullptr;
            prev = nullptr;
            text = nullptr;
        }
    };

    class ListIterator: public Iterator{
        private:
        Node *element;

        public:
        ListIterator(Node* element): element{element}{}
        bool hasNext() override;
        const char* next() override;
    };

    Node *start;
    Node *end;

    public:
    int size;

    LinkedList();
    LinkedList(const LinkedList& orig);
    ~LinkedList();

    int append(const char* text);
    int insert(const char* text, int p);
    int remove(int p);
    const char *get(int p);
    int index_of(const char *text);
    const char *first();
    const char *last();
    void visit_all(void (*work)(const char* t));

    Iterator* iterator();
};
}
#endif