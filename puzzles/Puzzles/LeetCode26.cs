namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
/// </summary>
public class LeetCode26
{
    public int Solve(int[] numbers)
    {
        var i = 1;
        var j = 1;
        while (j < numbers.Length)
        {
            if (numbers[j] != numbers[j - 1])
            {
                numbers[i] = numbers[j];
                i++;
            }

            j++;
        }

        return i;
    }
}
