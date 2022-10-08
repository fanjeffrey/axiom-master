using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode15Tests
{
    private LeetCode15 leetCode15;

    [TestInitialize]
    public void Setup()
    {
        leetCode15 = new LeetCode15();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { -1, 0, 1, 2, -1, -4 };
        var triplet1 = new List<int> { -1, -1, 2 };
        var triplet2 = new List<int> { -1, 0, 1 };
        var expected = new List<List<int>> { triplet1, triplet2 };

        var actual = leetCode15.Solve(numbers);

        Assert.AreEqual(expected.Count, actual.Count);
        for (var i = 0; i < expected.Count; i++)
        {
            Assert.AreEqual(expected[i][0], actual[i][0]);
            Assert.AreEqual(expected[i][1], actual[i][1]);
            Assert.AreEqual(expected[i][2], actual[i][2]);
        }
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 0, 1, 1 };
        var expected = new List<List<int>>();

        var actual = leetCode15.Solve(numbers);

        Assert.AreEqual(expected.Count, actual.Count);
        for (var i = 0; i < expected.Count; i++)
        {
            Assert.AreEqual(expected[i][0], actual[i][0]);
            Assert.AreEqual(expected[i][1], actual[i][1]);
            Assert.AreEqual(expected[i][2], actual[i][2]);
        }
    }

    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { 0, 0, 0 };
        var triplet1 = new List<int> { 0, 0, 0 };
        var expected = new List<List<int>> { triplet1 };

        var actual = leetCode15.Solve(numbers);

        Assert.AreEqual(expected.Count, actual.Count);
        for (var i = 0; i < expected.Count; i++)
        {
            Assert.AreEqual(expected[i][0], actual[i][0]);
            Assert.AreEqual(expected[i][1], actual[i][1]);
            Assert.AreEqual(expected[i][2], actual[i][2]);
        }
    }

    // [0,-3,-4,-2,-2,-1,1,-1,-3,-2]
    [TestMethod]
    public void Test4()
    {
        var numbers = new int[] { 0, -3, -4, -2, -2, -1, 1, -1, -3, -2 };
        var triplet1 = new List<int> { -1, 0, 1 };
        var expected = new List<List<int>> { triplet1 };

        var actual = leetCode15.Solve(numbers);

        Assert.AreEqual(expected.Count, actual.Count);
        for (var i = 0; i < expected.Count; i++)
        {
            Assert.AreEqual(expected[i][0], actual[i][0]);
            Assert.AreEqual(expected[i][1], actual[i][1]);
            Assert.AreEqual(expected[i][2], actual[i][2]);
        }
    }
}