namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/increasing-triplet-subsequence/
/// </summary>
public class LeetCode334
{
    public bool Solve(int[] numbers)
    {
        if (numbers == null || numbers.Length < 3) return false;

        var first = numbers[0];
        var second = int.MaxValue;

        var i = 0;
        while (++i < numbers.Length)
        {
            if (numbers[i] <= first)
                first = numbers[i];
            else if (numbers[i] <= second)
                second = numbers[i];
            else return true;
        }

        return false;
    }
}