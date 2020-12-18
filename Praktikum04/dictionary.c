#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

typedef struct Node{
    int storage;
    struct Node* next;
}NodeT;

typedef struct Head{
    struct Node* first;
}HeadT;


// mit static nur in diese datei bekannt, andere klasse/dateien haben kein zugriff darauf! (geschuetzt)
static HeadT dictionary[SIZE]; 

//Achtung, malloc in heap, array in stack

void init()
{
    HeadT head;
    head.first = NULL;

    for(int i = 0; i < SIZE; i++)
    {
        dictionary[i] = head; 
    }
}

int insert(int a)
{
    int position = a % SIZE;
    NodeT* new = malloc(sizeof(NodeT));

    if(new == NULL)
    {
        return 0;
    }

    //Falls Kopf leer, d.h. kein "erstes" Element vorhanden 
    if(dictionary[position].first == NULL)
    {
        new->storage = a;
        //das neue Element zeigt auf  , da es alleine im Array steht
        new->next = NULL;
        dictionary[position].first = new;    
        return 1;
    } 
        
    //Falls mindestens 1 Element schon da 
    new->storage = a;

    //das neue Element zeigt auf das alte Element an dieser arrayposition
    new->next = dictionary[position].first;
    dictionary[position].first = new;

    return 1;
}  

int member(int a)
{
    // zu erwartende Position
    int position = a % SIZE;
    
    // dort kein Element vorhanden
    if(dictionary[position].first == NULL)
    {
        return 0;
    }
    
    // sonst verkettete Liste dieser Elemente durchsuchen

    NodeT *temp = dictionary[position].first;

    while(temp->next != NULL)
    {
        if(temp->storage == a)
        {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0;
}

int delete(int a)
{
     // zu erwartende Position
    int position = a % SIZE;
    
    // dort kein Element vorhanden
    if(dictionary[position].first == NULL)
    {
        return 0;
    }

    NodeT *temp = dictionary[position].first;

    // Element Am Anfang der Liste (bzw. zuletzt hinzugefugt) 
    if(temp->storage == a)
    {
        // hat kein nachfolger
        if(temp->next == NULL)
        {
            dictionary[position].first = NULL;
            free(temp);
            return 1;
        }
        else
        {
            dictionary[position].first = temp->next;
            free(temp);
            return 1;
        }
    } 

    //Element nicht an 1. Position der Liste, Liste durchlaufen
    NodeT* prev;

    while(temp->next != NULL)
    {
        if(temp->storage == a)
        {
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    // Am Ende der Liste
    if(temp->next == NULL)
    {
        prev->next = NULL;
        free(temp);
        return 1;
    }

    // Mitte der Liste
    prev->next = temp->next;
    free(temp);
    return 1;

}

void displayDictionary()
{
    for(int i = 0; i < SIZE ; i++)
    {
        NodeT* temp = dictionary[i].first;

        while(temp->next != NULL)
        {
            printf("|%d|",temp->storage);
            temp = temp->next;
        }

        printf("\n");
    }
}
