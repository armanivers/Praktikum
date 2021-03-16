using System;

namespace arrayList
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Start!");

            ArrayList<int> l1 = new ArrayList<int>();

            for(int i = 0 ; i < 3; i++)
            {
                l1.Add(i);
            }

            ArrayList<int> l2 = l1;

            Console.WriteLine(l1);

            ArrayList<int> l3 = l1+l2;
            Console.WriteLine(l3);
        }
    }
}
