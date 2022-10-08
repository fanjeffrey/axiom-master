using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode334Tests
{
    private LeetCode334 leetCode334;

    [TestInitialize]
    public void Setup()
    {
        leetCode334 = new LeetCode334();
    }

    [TestMethod]
    public void Test1()
    {
        int[] numbers = { 1, 2, 3, 4, 5 };
        var expected = true;

        var actual = leetCode334.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        int[] numbers = { 5, 4, 3, 2, 1 };
        var expected = false;

        var actual = leetCode334.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test3()
    {
        int[] numbers = { 2, 1, 5, 0, 4, 6 };
        var expected = true;

        var actual = leetCode334.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test4()
    {
        int[] numbers = { 20, 100, 10, 12, 10, 100, 5, 13 };
        var expected = true;

        var actual = leetCode334.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }
}