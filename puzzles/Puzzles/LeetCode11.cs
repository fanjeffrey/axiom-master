namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/container-with-most-water/
/// </summary>
public class LeetCode11
{
    public int Solve(int[] heightArray)
    {
        if (heightArray == null || heightArray.Length < 2)
            throw new Exception("The input array doesn't meet the constraints.");

        var maxArea = 0;
        var left = 0;
        var right = heightArray.Length - 1;
        while (left < right)
        {
            maxArea = Math.Max(maxArea, (right - left) * Math.Min(heightArray[left], heightArray[right]));
            if (heightArray[left] < heightArray[right])
                left++;
            else
                right--;
        }

        return maxArea;
    }
}
