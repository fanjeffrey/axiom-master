using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode11Tests
{
    private LeetCode11 leetCode11;

    [TestInitialize]
    public void Setup()
    {
        leetCode11 = new LeetCode11();
    }

    [TestMethod]
    public void Test1()
    {
        var heightArray = new int[] { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        var expected = 49;

        var actual = leetCode11.Solve(heightArray);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        var heightArray = new int[] { 1, 1 };
        var expected = 1;

        var actual = leetCode11.Solve(heightArray);

        Assert.AreEqual(expected, actual);
    }
}
