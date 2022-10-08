using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode167Tests
{
    private LeetCode167 leetCode167;

    [TestInitialize]
    public void Setup()
    {
        leetCode167 = new LeetCode167();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 2, 7, 11, 15 };
        var target = 9;
        var expected = new int[] { 1, 2 };

        var actual = leetCode167.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 2, 3, 4 };
        var target = 6;
        var expected = new int[] { 1, 3 };

        var actual = leetCode167.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { -1, 0 };
        var target = -1;
        var expected = new int[] { 1, 2 };

        var actual = leetCode167.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }
}
