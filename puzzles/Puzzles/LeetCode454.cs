namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/4sum-ii/
/// </summary>
public class LeetCode454
{
    public int Solve(int[] nums1, int[] nums2, int[] nums3, int[] nums4)
    {
        var count = 0;
        var hash = new Dictionary<long, int>();

        int temp = 0;
        for (var i = 0; i < nums1.Length; i++)
            for (var j = 0; j < nums2.Length; j++)
                hash[nums1[i] + nums2[j]] = hash.TryGetValue(nums1[i] + nums2[j], out temp) ? temp + 1 : 1;

        for (var k = 0; k < nums3.Length; k++)
            for (var l = 0; l < nums4.Length; l++)
                if (hash.TryGetValue(0L - nums3[k] - nums4[l], out temp)) count += temp;

        return count;
    }
}
