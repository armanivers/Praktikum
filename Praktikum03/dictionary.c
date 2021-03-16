#include <stdio.h>
#define SIZE 2

typedef enum Flag{
    empty = 1,
    taken = 0,
    deleted = -1
}FlagT;

typedef struct Node{
    int storage;
    FlagT state;
}NodeT;

// mit static nur in diese datei bekannt, andere klasse/dateien haben kein zugriff darauf! (geschuetzt)
static NodeT dictionary[SIZE]; 

void init()
{
    NodeT n;
    n.storage = -1;
    n.state = empty;
    for(int i = 0; i < SIZE; i++)
    {
        dictionary[i] = n; 
    }
}

int findPositionOf(int a)
{
    int position = a % SIZE;
    for(int i = 0; i < SIZE ; i++)
        {
            if(position < SIZE){
                position++;
            } else
            {
                position = 0;
            }
            if(dictionary[position].state == taken && dictionary[position].storage == a){
                return position;
            }
        }
    return -1;
}

int insert(int a)
{
    int position = a % SIZE;
    if(dictionary[position].state == empty || dictionary[position].state == deleted)
    {
        NodeT new;
        new.storage = a;
        new.state = taken;
        dictionary[position] = new;    
        return 1;
    } 
        for(int i = 0 ; i < SIZE ; i++){
            if(position < SIZE){
                position++;
            } else
            {
                position = 0;
            }
            if(dictionary[position].state == empty || dictionary[position].state == deleted)
                {
                    NodeT new;
                    new.storage = a;
                    new.state = taken;
                    dictionary[position] = new;
                    return 1;   
                }
        }

    return 0;
}

int delete(int a)
{
    int position = a % SIZE;
    // fruher war statt taken -> empty, was eigentlich falsch ist
    if(dictionary[position].state == taken && dictionary[position].storage == a)
    {
        dictionary[position].state = deleted;
        dictionary[position].storage = -1;
        return 1;
    } else
    {
        int possiblePosition = findPositionOf(a);
        if(possiblePosition == -1)
        {
            // Wert gar nicht vorhanden
            return possiblePosition;
        } 
        else
        {
            // Wert gefunden, also loeschen 
            dictionary[possiblePosition].state = deleted;
            dictionary[possiblePosition].storage = -1;
            return 1;
        }
    }
}

int member(int a)
{
    int position = a % SIZE;

    // Hashposition leer, d.h. Wert nicht vorhanden
    if(dictionary[position].state == empty)
    {
        return 0;
        // Hashposition nicht leer und Wert ist gleich gesuchter Wert, d.h. Wert gefunden
    } else if(dictionary[position].state == taken && dictionary[position].storage == a)
    {
        return 1;
    } else if(findPositionOf(a) != -1)
    {
        // sonst suche alle andere Hashpositionen und liefere die 1, falls gefunden, sonst 0
        return 1;
    }
    return 0;
}

void displayDictionary()
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("| %i |",dictionary[i].storage);
    }
    printf("\n");
}