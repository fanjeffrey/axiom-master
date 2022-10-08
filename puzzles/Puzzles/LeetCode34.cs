namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/// </summary>
public class LeetCode34
{
    public int[] Solve(int[] numbers, int target)
    {
        if (numbers == null || numbers.Length == 0) return new int[] { -1, -1 };

        var firstPosition = FindFirstPostion(numbers, target);
        if (firstPosition == -1) return new int[] { -1, -1 };

        var lastPosition = FindLastPosition(numbers, target);
        return new int[] { firstPosition, lastPosition };
    }

    private int FindFirstPostion(int[] numbers, int target)
    {
        var left = 0;
        var right = numbers.Length - 1;
        while (left < right)
        {
            var mid = (left + right) / 2;
            if (numbers[mid] > target)
                right = mid - 1;
            else if (numbers[mid] == target)
                right = mid;
            else
                left = mid + 1;
        }

        return (numbers[left] == target) ? left : -1;
    }

    private int FindLastPosition(int[] numbers, int target)
    {
        var left = 0;
        var right = numbers.Length - 1;
        while (left < right)
        {
            var mid = (left + right + 1) / 2;
            if (numbers[mid] > target)
                right = mid - 1;
            else if (numbers[mid] == target)
                left = mid;
            else
                left = mid + 1;
        }

        return left;
    }
}
