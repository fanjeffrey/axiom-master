using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class ClosetNumbersTests
{
    [TestMethod]
    public void Solve_Test1()
    {
        var input = new int[] { 6, 2, 4, 10, 19, 21 };
        var expected = new string[] { "2 4", "4 6", "19 21" };

        var actual = new ClosetNumbers().Solve(input);

        Assert.IsTrue(expected.SequenceEqual(actual));
    }

    [TestMethod]
    public void Solve_Test2()
    {
        var input = new int[] { 8, 7, 5, 4, 3, 2, 1 };
        var expected = new string[] { "1 2", "2 3", "3 4", "4 5", "7 8" };

        var actual = new ClosetNumbers().Solve(input);

        Assert.IsTrue(expected.SequenceEqual(actual));
    }

    [TestMethod]
    public void Solve_Test3()
    {
        var input = new int[] { 6, 2 };
        var expected = new string[] { "2 6" };

        var actual = new ClosetNumbers().Solve(input);

        Assert.IsTrue(expected.SequenceEqual(actual));
    }
}

public class ClosetNumbers
{
    public string[] Solve(int[] input)
    {
        if (input?.Length < 2) return new string[] {};

        Array.Sort(input);

        var minDiff = int.MaxValue;
        var dict = new Dictionary<int, List<string>>();

        for (var i = 0; i < input.Length - 1; i++)
        {
            var diff = Math.Abs(input[i + 1] - input[i]);
            if (diff > minDiff) continue;

            minDiff = diff;
            var pair = $"{Math.Min(input[i + 1], input[i])} {Math.Max(input[i + 1], input[i])}";
            if (dict.ContainsKey(diff))
            {
                dict[diff].Add(pair);
            }
            else
            {
                dict[diff] = new List<string> { pair };
            }
        }

        return dict[minDiff].ToArray();
    }
}