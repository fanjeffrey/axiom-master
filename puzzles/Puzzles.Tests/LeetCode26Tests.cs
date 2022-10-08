using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode26Tests
{
    private LeetCode26 leetCode26;

    [TestInitialize]
    public void Setup()
    {
        leetCode26 = new LeetCode26();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        var expectedNumbers = new int[] { 0, 1, 2, 3, 4 };

        var k = leetCode26.Solve(numbers);

        Assert.AreEqual(5, k);
        for (var i = 0; i < k; i++)
        {
            Assert.AreEqual(expectedNumbers[i], numbers[i]);
        }
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 0, 1, 1, 1, 2, 3, 3, 3, 4, 4, 4 };
        var expectedNumbers = new int[] { 0, 1, 2, 3, 4 };

        var k = leetCode26.Solve(numbers);

        Assert.AreEqual(5, k);
        for (var i = 0; i < k; i++)
        {
            Assert.AreEqual(expectedNumbers[i], numbers[i]);
        }
    }

    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { 4, 4 };
        var expectedNumbers = new int[] { 4 };

        var k = leetCode26.Solve(numbers);

        Assert.AreEqual(1, k);
        for (var i = 0; i < k; i++)
        {
            Assert.AreEqual(expectedNumbers[i], numbers[i]);
        }
    }

    [TestMethod]
    public void Test4()
    {
        var numbers = new int[] { 1, 1, 1, 1, 1, 1, 1 };
        var expectedNumbers = new int[] { 1 };

        var k = leetCode26.Solve(numbers);

        Assert.AreEqual(1, k);
        for (var i = 0; i < k; i++)
        {
            Assert.AreEqual(expectedNumbers[i], numbers[i]);
        }
    }
}
