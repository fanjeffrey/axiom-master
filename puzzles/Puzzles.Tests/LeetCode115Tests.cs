using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode115Tests
{
    [TestMethod]
    public void Test1()
    {
        var source = "rabbbit";
        var target = "rabbit";

        var actual = new LeetCode115().NumDistinct(source, target);

        Assert.AreEqual(3, actual);
    }

    [TestMethod]
    public void Test2()
    {
        var source = "babgbag";
        var target = "bag";

        var actual = new LeetCode115().NumDistinct(source, target);

        Assert.AreEqual(5, actual);
    }

}

internal class LeetCode115
{
    public int NumDistinct(string s, string t)
    {
        var m = s.Length;
        var n = t.Length;
        if (m < n) return 0;

        var dp = new int[m + 1, n + 1];
        for (var i = 0; i <= m; i++) dp[i, 0] = 1;

        for (var i = 1; i <= m; i++)
        {
            for (var j = 1; j <= n; j++)
            {
                if (t[j - 1] == s[i - 1])
                    dp[i, j] = dp[i - 1, j - 1] + dp[i - 1, j];
                else
                    dp[i, j] = dp[i - 1, j];
            }
        }

        return dp[m, n];
    }
}