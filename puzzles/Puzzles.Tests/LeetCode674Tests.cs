using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode674Tests
{
    private LeetCode674 leetCode674;

    [TestInitialize]
    public void Setup()
    {
        leetCode674 = new LeetCode674();
    }

    [TestMethod]
    public void Test1()
    {
        int[] numbers = { 1, 3, 5, 7, 2, 4, 6, 8, 10 };
        var expected = 5;

        var actual = leetCode674.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }
}