namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/house-robber/
/// </summary>
public class HouseRobber
{
    public int Rob(int[] numbers)
    {
        if (numbers == null || numbers.Length == 0) return 0;

        if (numbers.Length == 1) return numbers[0];

        var prev2 = numbers[0];
        var prev1 = Math.Max(prev2, numbers[1]);
        var maxLoot = prev1;

        for (var i = 2; i < numbers.Length; i++)
        {
            maxLoot = Math.Max(numbers[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = maxLoot;
        }

        return Math.Max(prev2, prev1);
    }
}
