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
        foreach (var c in "abcdefghijklmnopqrstuvwxyz") letters[c] = 0;
        var last = 0;
        var current = 0;
        for (var i = 0; i < s.Length; i++)
        {
            current = last + 1;
            last = ((last + current) % mod - letters[s[i]] % mod + mod) % mod;
            letters[s[i]] = current;
        }

        return last % mod;
    }
}
