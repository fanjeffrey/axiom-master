using System;

namespace Puzzles
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            new UintMedianFinderDemo().DemoWith1BillionData();

            Console.WriteLine("Press Enter to exit...");
            Console.ReadLine();
        }
    }
}
