using System;

namespace Strukturen
{
    class Program
    {
        struct Point
        {
            public int x;
            public int y;
            public Point(int x, int y)
            {
                this.x = x;
                this.y = y;
            }
        }
        static void Main(string[] args)
        {
            Point p1;
            p1.x = 10;
            p1.y = 20;

            Point p2 = new Point(50,70);
            Point p3 = p2;

            p3.x = 100;
            p3.y = 200;

            Console.WriteLine("P1 = X{0} Y{1}",p1.x,p1.x);
            Console.WriteLine("P2 = X{0} Y{1}",p2.x,p2.x);
            Console.WriteLine("P3 = X{0} Y{1}",p3.x,p3.x);
        }
    }
}
