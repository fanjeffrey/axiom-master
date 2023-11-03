namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/house-robber/
/// </summary>
public class HouseRobber
{
    public int Rob(int[] nums)
    {
        if (nums == null || nums.Length == 0) return 0;

        if (nums.Length == 1) return nums[0];

        var prev2 = nums[0];
        var prev1 = Math.Max(prev2, nums[1]);
        var maxLoot = prev1;
        for (var i = 2; i < nums.Length; i++)
        {
            maxLoot = Math.Max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = maxLoot;
        }

        return maxLoot;
    }
}
