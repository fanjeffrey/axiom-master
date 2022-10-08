namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
/// </summary>
public class LeetCode167
{
    public int[] Solve(int[] numbers, int target)
    {
        if (numbers == null || numbers.Length < 2)
            throw new ArgumentException("The input array doesn't meet the constraints.");

        var head = 0;
        var tail = numbers.Length - 1;
        while (head < tail)
        {
            if (numbers[head] > target / 2 || numbers[tail] < target / 2) break;

            var sum = numbers[head] + numbers[tail];
            if (sum > target)
                tail--;
            else if (sum < target)
                head++;
            else
                return new int[] { head + 1, tail + 1 };
        }

        throw new Exception("No solution found within the input array.");
    }
}
