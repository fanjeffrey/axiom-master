using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode34Tests
{
    private LeetCode34 leetCode34;

    [TestInitialize]
    public void Setup()
    {
        leetCode34 = new LeetCode34();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 5, 7, 7, 8, 8, 10 };
        var target = 8;
        var expected = new int[] { 3, 4 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 5, 5, 7, 8, 8, 10 };
        var target = 5;
        var expected = new int[] { 0, 1 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { 5, 7, 7, 8, 10, 10 };
        var target = 10;
        var expected = new int[] { 4, 5 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test4()
    {
        var numbers = new int[] { 5, 7, 7, 8, 8, 8, 10 };
        var target = 5;
        var expected = new int[] { 0, 0 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test5()
    {
        var numbers = new int[] { 5, 7, 7, 8, 8, 9, 10 };
        var target = 10;
        var expected = new int[] { 6, 6 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test8()
    {
        var numbers = new int[] { 8, 8, 8, 8, 8, 8 };
        var target = 8;
        var expected = new int[] { 0, 5 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test9()
    {
        var numbers = new int[] { 5, 7, 7, 8, 8, 10 };
        var target = 88;
        var expected = new int[] { -1, -1 };

        var actual = leetCode34.Solve(numbers, target);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }
}
