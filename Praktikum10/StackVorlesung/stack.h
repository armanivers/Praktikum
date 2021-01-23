#include <iostream>

#include "exception.h"
template <class T>

class Stack
{
private:
  struct element
  {
    T key;
    element *next;
    element(T key, element *ptr) : key{key}, next{ptr} {}
  };
  element *top;

public:
  Stack();
  ~Stack();
  Stack(const Stack &orig);
  int push(T key);
  T pop();
};

template <class T>
Stack<T>::Stack() : top{nullptr} {}
template <class T>
Stack<T>::~Stack()
{
  while (top != nullptr)
  {
    pop();
  }
}

template <class T>
Stack<T>::Stack(const Stack &orig) : Stack{}
{
  Stack tmp;
  element *ptr = orig.top;
  while (ptr != nullptr)
  {
    tmp.push(ptr->key);
    ptr = ptr->next;
  }
  T k;
  while (tmp.top != nullptr)
  {
    push(tmp.pop());
  }
}

template <class T>
int Stack<T>::push(T k)
{
  element *neu = new element{k, top};
  if (neu)
  {
    top = neu;
    return 1;
  }
  else
  {
    return 0;
  }
}

template <class T>
T Stack<T>::pop()
{

  if (top == nullptr)
  {
    throw empty_stack_exception("Stack Leer");
  }
  else
  {
    T k = top->key;
    element *tmp = top;
    top = top->next;
    delete tmp;
    return k;
  }
}