namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/number-of-unique-good-subsequences/
/// </summary>
public class LeetCode1987
{
    public int NumberOfUniqueGoodSubsequences(string binary)
    {
        const int mod = (int)1e9 + 7;
        var dp = new int[2];
        for (var i = 0; i < binary.Length; i++)
        {
            dp[binary[i] - '0'] = (dp[0] + dp[1] + binary[i] - '0') % mod;
        }

        return (dp[0] + dp[1] + (binary.Contains('0') ? 1 : 0)) % mod;
    }
}
