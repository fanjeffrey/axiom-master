using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode198Tests
{
    private HouseRobber houseRobber;

    [TestInitialize]
    public void Setup()
    {
        houseRobber = new HouseRobber();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 1, 2, 3, 1 };
        var expected = 4;

        var actual = houseRobber.Rob(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        int[] numbers = { 2, 7, 9, 3, 1 };
        var expected = 12;

        var actual = houseRobber.Rob(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test3()
    {
        int[] numbers = { 6, 7, 1, 3, 8, 2, 4 };
        var expected = 19;

        var actual = houseRobber.Rob(numbers);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test4()
    {
        int[] numbers = { 5, 3, 4, 11, 2 };
        var expected = 16;

        var actual = houseRobber.Rob(numbers);

        Assert.AreEqual(expected, actual);
    }
}