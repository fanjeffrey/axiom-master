using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode454Tests
{
    private LeetCode454 leetCode454;

    [TestInitialize]
    public void Setup()
    {
        leetCode454 = new LeetCode454();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers1 = new int[] { 1, 2 };
        var numbers2 = new int[] { -2, -1 };
        var numbers3 = new int[] { -1, 2 };
        var numbers4 = new int[] { 0, 2 };
        var expected = 2;

        var actual = leetCode454.Solve(numbers1, numbers2, numbers3, numbers4);

        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        var numbers1 = new int[] { 0 };
        var numbers2 = new int[] { 0 };
        var numbers3 = new int[] { 0 };
        var numbers4 = new int[] { 0 };
        var expected = 1;

        var actual = leetCode454.Solve(numbers1, numbers2, numbers3, numbers4);

        Assert.AreEqual(expected, actual);
    }
}
