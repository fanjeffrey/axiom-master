using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode300Tests
{
    private LeetCode300 leetCode300;

    [TestInitialize]
    public void Setup()
    {
        leetCode300 = new LeetCode300();
    }

    [TestMethod]
    public void Test1()
    {
        int[] numbers = { 10, 9, 2, 5, 3, 7, 101, 18 };
        var expected = 4;

        var actual = leetCode300.SolveWithRecursion(numbers);
        var actual1 = leetCode300.SolveWithMemoization(numbers);
        var actual2 = leetCode300.SovleWithTabulation(numbers);
        var actual4 = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
        Assert.AreEqual(expected, actual1);
        Assert.AreEqual(expected, actual2);
        Assert.AreEqual(expected, actual4);
    }

    [TestMethod]
    public void Test2()
    {
        int[] numbers = { 0, 1, 0, 3, 2, 3 };
        var expected = 4;

        var actual = leetCode300.SolveWithRecursion(numbers);
        var actual1 = leetCode300.SolveWithMemoization(numbers);
        var actual2 = leetCode300.SovleWithTabulation(numbers);
        var actual4 = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
        Assert.AreEqual(expected, actual1);
        Assert.AreEqual(expected, actual2);
        Assert.AreEqual(expected, actual4);
    }

    [TestMethod]
    public void Test3()
    {
        int[] numbers = { 3, 10, 2, 8, 9, 11 };
        var expected = 4;

        var actual = leetCode300.SolveWithRecursion(numbers);
        var actual1 = leetCode300.SolveWithMemoization(numbers);
        var actual2 = leetCode300.SovleWithTabulation(numbers);
        var actual4 = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
        Assert.AreEqual(expected, actual1);
        Assert.AreEqual(expected, actual2);
        Assert.AreEqual(expected, actual4);
    }

    [TestMethod]
    public void Test4()
    {
        int[] numbers = { 7, 7, 7, 7, 7, 7, 7 };
        var expected = 1;

        var actual = leetCode300.SolveWithRecursion(numbers);
        var actual1 = leetCode300.SolveWithMemoization(numbers);
        var actual2 = leetCode300.SovleWithTabulation(numbers);
        var actual4 = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
        Assert.AreEqual(expected, actual1);
        Assert.AreEqual(expected, actual2);
        Assert.AreEqual(expected, actual4);
    }

    [TestMethod]
    public void Test5()
    {
        int[] numbers = { 4, 10, 4, 3, 8, 9 };
        var expected = 3;

        var actual = leetCode300.SolveWithRecursion(numbers);
        var actual1 = leetCode300.SolveWithMemoization(numbers);
        var actual2 = leetCode300.SovleWithTabulation(numbers);
        var actual4 = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
        Assert.AreEqual(expected, actual1);
        Assert.AreEqual(expected, actual2);
        Assert.AreEqual(expected, actual4);
    }

    [TestMethod]
    public void Test6()
    {
        int[] numbers = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12, 11 };
        var expected = 6;

        var actual = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test7()
    {
        int[] numbers = { 1, 2, 4, 3, 5, 4, 7, 2 };
        var expected = 5;

        var actual = leetCode300.Solve(numbers);

        Assert.AreEqual(expected, actual);
    }
}