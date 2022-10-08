using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode295Tests
{
    private LeetCode295 leetCode295;

    [TestInitialize]
    public void Setup()
    {
        leetCode295 = new LeetCode295();
    }

    [TestMethod]
    public void Test1()
    {
        leetCode295.AddNum(1);
        var expected = 1d;
        var actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(2);
        expected = 1.5;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(3);
        expected = 2;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(4);
        expected = 2.5;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);
    }

    [TestMethod]
    public void Test2()
    {
        leetCode295.AddNum(3);
        var expected = 3d;
        var actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(2);
        expected = 2.5;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(1);
        expected = 2;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);

        leetCode295.AddNum(-1);
        expected = 1.5;
        actual = leetCode295.FindMedian();
        Assert.AreEqual(expected, actual);
    }
}