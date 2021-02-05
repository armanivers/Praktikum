using System;

namespace Praktikum12
{
    class LinkedList<T>
    {
       internal class Node 
       {
           public Node(T data, Node next = null)
           {
               this.data = data;
               this.next = next;
           }
           public Node next {get; set;}
           // ohne set -> kann man den Wert nur 1 mal setzen (noch sicherer)
           public T data {get;}
       }
       internal class ListIterator : I_Iterator<T>
       {
           Node currentElement;
           public ListIterator(Node currentElement)
           {
               this.currentElement = currentElement;
           }
           public bool HasNext()
           {
               return (currentElement != null);
           }

           public T Next()
           {
                Node temp = currentElement;
                currentElement = currentElement.next;
                return temp.data;
           }
       }
       internal Node start;
       internal Node end;
       private int size;
       public int Size
       {
           get
           {
               return size;
           }

       }

       public LinkedList()
       {
           size = 0;
           // in c# attribute haben standartwerte (null), also = null nicht notwendig
           start = end = null;
       }

       public bool Add(T element)
       {
           // falls leere Liste
           if(start == null)
           {
               start = end = new Node(element);
               size++;
               return true;
           }

            // Liste hat mindestens 1 Element
            Node newElement = new Node(element);
            end.next = newElement;
            end = newElement;
            size++;
            return true;
       }

       public bool Remove(int position)
       {
            // ungueltige Position oder leere Liste
            if(position < 0 || position > size-1) return false;

            // das erste Element loeschen
            if(position == 0)
            {
                start = start.next;
                size--;
                return true;
            }

            // Element in der Mitte oder am Ende loeschen
            Node prev = start;
            Node current = start;

            for(int i = 0; i < position; i++)
            {
                prev = current;
                current = current.next;
            }

            if(position == size-1)
            {
                prev.next = null;
                end = prev;
                size--;
                return true;
            }

            prev.next = current.next;
            size--;
            return true;
       }

       public void VisitAllDefault()
       {
           Node temp = start;
           while(temp != null)
           {
               Console.WriteLine(temp.data);
               temp = temp.next;
           }
       }

       public void VisitAllIterator()
       {
           I_Iterator<T> iterator = Iterator();

           while(iterator.HasNext())
           {
               Console.WriteLine(iterator.Next());
           }
       }


        // hier mit delegate -> wie in c++ (funktion ubergeben koennen)
       public void VisitAllDelegate(myDelType<T> Work)
       {
           I_Iterator<T> iterator = Iterator();

           while(iterator.HasNext())
           {
               Work(iterator.Next());
           }
       }
       

    
       public ListIterator Iterator()
       {
           //Node temp = start;
           return new ListIterator(start);
       }

    }
}
