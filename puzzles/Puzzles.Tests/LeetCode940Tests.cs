using System;
using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode940Tests
{
    [TestMethod]
    public void Test0()
    {
        var s = "a";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(1, actual);
    }

    [TestMethod]
    public void Test1()
    {
        var s = "abc";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(7, actual);
    }

    [TestMethod]
    public void Test2()
    {
        var s = "aba";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(6, actual);
    }

    [TestMethod]
    public void Test3()
    {
        var s = "aaa";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(3, actual);
    }

    [TestMethod]
    public void Test4()
    {
        var s = "abca";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(14, actual);
    }

    [TestMethod]
    public void Test5()
    {
        var s = "bebb";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(9, actual);
    }

    [TestMethod]
    public void Test6()
    {
        var s = "zchmliaqdgvwncfatcfivphddpzjkgyygueikthqzyeeiebczqbqhdytkoawkehkbizdmcnilcjjlpoeoqqoqpswtqdpvszfaksn";
        var actual = new LeetCode940().DistinctSubseqII(s);
        Assert.AreEqual(97915677, actual);
    }
}
