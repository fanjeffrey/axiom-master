namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
/// </summary>
public class LeetCode673
{
    public int Solve(int[] numbers)
    {
        if (numbers == null || numbers.Length <= 0) return 0;

        var lengthArray = new int[numbers.Length];
        var countArray = new int[numbers.Length];
        var maxLength = lengthArray[0] = 1;
        var countOfLIS = countArray[0] = 1;

        for (var i = 1; i < numbers.Length; i++)
        {
            lengthArray[i] = countArray[i] = 1;

            for (var j = 0; j < i; j++)
            {
                if (numbers[i] <= numbers[j]) continue;

                if (lengthArray[i] < lengthArray[j] + 1)
                {
                    lengthArray[i] = lengthArray[j] + 1;
                    countArray[i] = countArray[j];
                }
                else if (lengthArray[i] == lengthArray[j] + 1)
                {
                    countArray[i] += countArray[j];
                }
            }

            if (maxLength < lengthArray[i])
            {
                maxLength = lengthArray[i];
                countOfLIS = countArray[i];
            }
            else if (maxLength == lengthArray[i])
            {
                countOfLIS += countArray[i];
            }
        }

        return countOfLIS;
    }
}