#include <stdio.h>
#define SIZE 2

typedef enum Flag{
    free = 1,
    used = 0
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
    n.state = free;
    for(int i = 0; i < SIZE; i++)
    {
        dictionary[i] = n; 
    }
}

int insert(int a)
{
    int position = a % SIZE;
    if(dictionary[position].state == free)
    {
        NodeT new;
        new.storage = a;
        new.state = used;
        dictionary[position] = new;    
        return 1;
    } else
    {
        for(int i = 0 ; i < SIZE ; i++){
            if(position < SIZE){
                position++;
            } else
            {
                position = 0;
            }
            if(dictionary[position].state == free)
                {
                    NodeT new;
                    new.storage = a;
                    new.state = used;
                    dictionary[position] = new;
                    return 1;   
                }
        }
    }
    return 0;
}

int delete(int a)
{
    int position = a % SIZE;
    if(dictionary[position].state == 0 && dictionary[position].storage == free)
    {
        dictionary[position].state = free;
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
            dictionary[possiblePosition].state = free;
            dictionary[possiblePosition].storage = -1;
            return 1;
        }
    }
}

int member(int a)
{
    int position = a % SIZE;

    // Hashposition leer, d.h. Wert nicht vorhanden
    if(dictionary[position].state == free)
    {
        return 0;
        // Hashposition nicht leer und Wert ist gleich gesuchter Wert, d.h. Wert gefunden
    } else if(dictionary[position].state == used && dictionary[position].storage == a)
    {
        return 1;
    } else
    {
        // sonst suche alle andere Hashpositionen und liefere die position oder ggf -1 , falls Wert nicht gefunden
        return findPositionOf(a);
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
            if(dictionary[position].state == free && dictionary[position].storage == a){
                return position;
            }
        }
    return -1;
}

void displayDictionary()
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("| %i |",dictionary[i].storage);
    }
    printf("\n");
}