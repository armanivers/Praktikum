using System;

namespace arrayList
{
    class ArrayList<T>
    {
        internal class Node 
        {
            public Node(T key)
            {
                this.key = key;
                this.next = null;
            }
            public T key;
            public Node next;
        }
        private Node start;
        private Node end;
        private int count;
        public int Count { get{return count;}}

        public ArrayList()
        {
            start = end = null;
            count = 0;
        }

        public bool Add(T key)
        {
            if(start==null)
            {
                start = end = new Node(key);
                count++;
                return true;
            }

            end = end.next = new Node(key);
            count++;
            return true;
        }

        public bool Remove(int p)
        {
            if(p < 0 || p > Count) return false;

            int count = 0;
            Node temp = start;
            for(int i = 0 ; i < p; i++)
            {
                temp=temp.next;
            }
            return true;
        }

        public T Get(int p)
        {
            Node temp = start;
            for(int i = 0; i < p; i++)
            {
                temp=temp.next;
            }
            return temp.key;
        }

        public bool Insert(int p, T key)
        {
            if(p < 0) return false;
            if(p > Count) return Add(key);

            Node temp = start;
            for(int i = 0; i <= p; i++)
            {
                temp=temp.next;
            }
            temp.key = key;
            return true;
        }
        public T this[int i]
        {
            get{return Get(i);}
            set{Insert(i,value);}
        }

        public override string ToString()
        {
            string result = "";
            for(int i = 0; i < Count; i++)
            {
                result += this[i];
            }
            return result;
        }

        public static ArrayList<T> operator+(ArrayList<T> l1, ArrayList<T> l2)
        {
            ArrayList<T> result = new ArrayList<T>();
            for(int i = 0; i < l1.Count; i++)
            {
                result.Add(l1[i]);
            }
            for(int i = 0; i < l2.Count; i++)
            {
                result.Add(l2[i]);
            }
            return result;
        }
    }
}
