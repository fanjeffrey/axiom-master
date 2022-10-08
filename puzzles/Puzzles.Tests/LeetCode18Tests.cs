using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode18Tests
{
    private LeetCode18 leetCode18;

    [TestInitialize]
    public void Setup()
    {
        leetCode18 = new LeetCode18();
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 1, 0, -1, 0, -2, 2 };
        var target = 0;
        var triplet1 = new List<int> { -2, -1, 1, 2 };
        var triplet2 = new List<int> { -2, 0, 0, 2 };
        var triplet3 = new List<int> { -1, 0, 0, 1 };
        var expected = new List<IList<int>> { triplet1, triplet2, triplet3 };

        var actual = leetCode18.Solve(numbers, target);
        Verify(expected, actual);

        var actual2 = leetCode18.FourSum(numbers, target);
        Verify(expected, actual2);
    }

    private void Verify(IList<IList<int>> expected, IList<IList<int>> actual)
    {
        Assert.AreEqual(expected.Count, actual.Count);
        for (var i = 0; i < expected.Count; i++)
        {
            Assert.AreEqual(expected[i][0], actual[i][0]);
            Assert.AreEqual(expected[i][1], actual[i][1]);
            Assert.AreEqual(expected[i][2], actual[i][2]);
            Assert.AreEqual(expected[i][3], actual[i][3]);
        }
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 2, 2, 2, 2, 2 };
        var target = 8;
        var triplet1 = new List<int> { 2, 2, 2, 2 };
        var expected = new List<IList<int>> { triplet1 };

        var actual = leetCode18.Solve(numbers, target);
        Verify(expected, actual);

        var actual2 = leetCode18.FourSum(numbers, target);
        Verify(expected, actual2);
    }

    //[-2,-1,-1,1,1,2,2]
    //0
    [TestMethod]
    public void Test3()
    {
        var numbers = new int[] { -2, -1, -1, 1, 1, 2, 2 };
        var target = 0;
        var triplet1 = new List<int> { -2, -1, 1, 2 };
        var triplet2 = new List<int> { -1, -1, 1, 1 };
        var expected = new List<IList<int>> { triplet1, triplet2 };

        var actual = leetCode18.Solve(numbers, target);
        Verify(expected, actual);

        var actual2 = leetCode18.FourSum(numbers, target);
        Verify(expected, actual2);
    }

    //[-1000000000,-1000000000,1000000000,-1000000000,-1000000000]
    //294967296
    [TestMethod]
    public void Test4()
    {
        var numbers = new int[] { -1000000000, -1000000000, 1000000000, -1000000000, -1000000000 };
        var target = 294967296;
        var expected = new List<IList<int>> { };

        var actual = leetCode18.Solve(numbers, target);
        Verify(expected, actual);

        var actual2 = leetCode18.FourSum(numbers, target);
        Verify(expected, actual2);
    }
}