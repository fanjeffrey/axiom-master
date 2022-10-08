using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode673Tests
{
    private LeetCode673 leetCode673;

    [TestInitialize]
    public void Setup()
    {
        leetCode673 = new LeetCode673();
    }

    [TestMethod]
    public void Test1()
    {
        int[] numbers = { 1, 3, 5, 4, 7 };
        var expected = 2;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test11()
    {
        int[] numbers = { 1, 3, 5, 4 };
        var expected = 2;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        int[] numbers = { 2, 2, 2, 2, 2 };
        var expected = 5;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test3()
    {
        int[] numbers = { 2 };
        var expected = 1;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test4()
    {
        int[] numbers = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12, 11 };
        var expected = 4;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test5()
    {
        int[] numbers = { 1, 2, 4, 3, 5, 4, 7, 2 };
        var expected = 3;

        var actual = leetCode673.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }
}