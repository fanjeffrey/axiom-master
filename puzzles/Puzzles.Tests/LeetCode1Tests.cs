using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode1Tests
{
    private LeetCode1 leetCode1;

    [TestInitialize]
    public void Setup()
    {
        leetCode1 = new LeetCode1();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 2, 7, 11, 15 };
        var expected = new int[] { 0, 1 };

        var actual = leetCode1.Solve(numbers, 9);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 3, 2, 4 };
        var expected = new int[] { 1, 2 }; ;

        var actual = leetCode1.Solve(numbers, 6);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }

    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { 3, 3 };
        var expected = new int[] { 0, 1 };

        var actual = leetCode1.Solve(numbers, 6);

        Assert.AreEqual(expected[0], actual[0]);
        Assert.AreEqual(expected[1], actual[1]);
    }
}