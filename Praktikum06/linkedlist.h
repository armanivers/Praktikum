class LinkedList{

    public:
    
    int size;
    LinkedList();
    
    int append(const char* text);
    int insert(const char* text, int p);
    int remove(int p);
    const char *get(int p);
    int index_of(const char *text);
    const char *first();
    const char *last();
    void visit_all(void (*work)(const char* t));

    private:
    // interne Klasse
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

    // in C structs sind leichtgewichtige klasse, kein typedef notw.
    /*
    struct Node{
        Node* next;
        Node* previous;
        char* text;
    };
    */

    Node *start;
    Node *end;
};
