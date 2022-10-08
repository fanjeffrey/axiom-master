namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/longest-continuous-increasing-subsequence/
/// </summary>
public class LeetCode674
{
    public int Solve(int[] numbers)
    {
        if (numbers == null || numbers.Length == 0) return 0;

        int maxCis = 1;
        int continuousIncreasingLength = 1;
        for (var i = 1; i < numbers.Length; i++)
        {
            if (numbers[i] > numbers[i - 1])
            {
                continuousIncreasingLength++;
            }
            else
            {
                if (maxCis < continuousIncreasingLength)
                    maxCis = continuousIncreasingLength;
                continuousIncreasingLength = 1;
            }
        }

        return Math.Max(maxCis, continuousIncreasingLength);
    }
}