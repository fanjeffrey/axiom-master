namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/distinct-subsequences-ii/
/// </summary>
public class LeetCode940
{
    public int DistinctSubseqII(string s)
    {
        var mod = (int)1e9 + 7;
        var letters = new Dictionary<char, int>();
        foreach(var c in "abcdefghijklmnopqrstuvwxyz") letters[c] = 0;
        var totalCount = 0;
        int newCount;
        for(var i = 0; i < s.Length; i ++)
        {
            newCount = totalCount + 1;
            totalCount = ((totalCount + newCount) % mod - letters[s[i]] % mod + mod) % mod;
            letters[s[i]] = newCount;
        }

        return (totalCount + mod) % mod;
    }
}
