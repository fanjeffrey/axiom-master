using System;
using System.Diagnostics;
using System.IO;

namespace Puzzles
{
    public class Puzzle2
    {
        public bool Solve(int[] path)
        {
            var prevSteps = 0;

            for (var i = 1; i < path.Length; i++)
            {
                if (path[i] <= path[i - 1])
                {
                    Console.WriteLine("Can't go backwards.");
                    return false;
                }

                var currentSteps = path[i] - path[i - 1];

                if (currentSteps < prevSteps - 1 || currentSteps > prevSteps + 1)
                {
                    Console.WriteLine($"The steps you're taking is out of the range [{prevSteps - 1}, {prevSteps}, {prevSteps + 1}].");
                    return false;
                }

                prevSteps = currentSteps;
            }

            return true;
        }
    }
}