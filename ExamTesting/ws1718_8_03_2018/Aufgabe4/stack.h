#ifndef _STACKH_
#define _STACKH_

template <class T>
class Stack 
{
    private:
    // kein internal here?
    class Node 
    {
        public:
        T key;
        Node* next;
        Node(T key) : key{key}, next{nullptr} {}
    };
    
    Node* top;

    Stack();
    Stack(const Stack<T>& o);
    ~Stack();

    int push(T key);
    T pop();
};
#endif

template <class T>
Stack<T>::Stack() : top{nullptr} {}

template <class T>
Stack<T>::Stack(const Stack<T>& orig)
{
    //...
}

template <class T>
Stack<T>::~Stack()
{
    while(top != nullptr) 
    {
        pop();
    }
}

template <class T>
int Stack<T>::push(T key)
{
    Node* neu = new Node(key);
    if(neu == nullptr) return 0;

    if(top == nullptr)
    {
        top = neu;
        return 1;
    }

    neu->next = top;
    top = neu;
    return 1;
}

template <class T>
T Stack<T>::pop()
{
    if(top == nullptr) return nullptr; //throw new Exception("fehler");

    T tempK = top->key;
    Node* tempN = top;
    top = top->next;
    free(tempN);
    return tempK;
}