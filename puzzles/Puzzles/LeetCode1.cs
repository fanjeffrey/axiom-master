namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/two-sum/
/// </summary>
public class LeetCode1
{
    public int[] Solve(int[] numbers, int target)
    {
        var mapping = new Dictionary<int, int>();

        mapping[numbers[0]] = 0;

        for (var i = 1; i < numbers.Length; i++)
        {
            var d = target - numbers[i];
            if (mapping.ContainsKey(d))
                return new int[] { mapping[d], i };
            else
                mapping[numbers[i]] = i;
        }

        throw new Exception("The input array doesn't meet the constraints.");
    }
}
