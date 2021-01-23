#ifndef _STACK_H_
#define _STACH_H_

#include <iostream>
#include "exception.h"

namespace fhdo_pk2{
    
    template<class T>
    class Stack{
        
        private:
        int maxSize;
        int currentSize;
        T *memory;

        public:
        Stack();
        Stack(int maxSize);
        ~Stack();
        Stack(const Stack &orig);

        T pop();
        int push(T data);

        inline int getSize() const
        {
            return currentSize;
        }

        inline bool isFull() const
        {
            return (currentSize >= maxSize);
        }

        inline T getElement(int index) const
        {
            // wie returne ich nullptr bei template klassen?
            if(index < 0 || index > currentSize) return 0;

            return memory[index];
        }

    };

    template<class T>
    Stack<T>::Stack() : maxSize{5}
    {
        std::cout << "Konstruktor" << std::endl;
        
        currentSize = 0;
        memory = new T[maxSize];
    }


    template<class T>
    Stack<T>::Stack(int maxSize) : maxSize{maxSize}
    {
        std::cout << "Konstruktor" << std::endl;

        currentSize = 0;
        memory = new T[maxSize];
    }

    template<class T>
    Stack<T>::~Stack()
    {
        std::cout << "Destruktor" << std::endl;

        delete[](memory);
    }

    template<class T>
    Stack<T>::Stack(const Stack &orig)
    {
        std::cout << "Copy Konstruktor" << std::endl;

        for(int i = 0; i < orig.currentSize(); i++)
        {
            if(isFull()) return;
            push(orig.getElement(i));
        }
    }

    template<class T>
    T Stack<T>::pop()
    {
        if(currentSize < 0)
        {
            throw empty_stack_exception("Stack Leer!");
        }
        else
        {
        currentSize--;
        return memory[currentSize];
        }
    }

    template<class T>
    int Stack<T>::push(T data)
    {
        if(currentSize >= maxSize) return 0;

        memory[currentSize] = data;
        currentSize++;
        return 1;
    }

    template<class T>
    std::ostream& operator<<(std::ostream& ausgabe, const Stack<T>& s)
    {
        for(int i = 0; i < s.getSize(); i++)
        {
            ausgabe << s.getElement(i) << std::endl;
        }
         return ausgabe << std::endl;
    }
}
#endif