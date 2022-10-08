using System;
using System.Diagnostics;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class FibonacciTests
{
    private Fibonacci finonacci;

    [TestInitialize]
    public void Setup()
    {
        finonacci = new Fibonacci();
    }

    [TestMethod]
    public void Test1()
    {
        Assert.AreEqual(0, finonacci.Recursive(0));
        Assert.AreEqual(1, finonacci.Recursive(1));
        Assert.AreEqual(1, finonacci.Recursive(2));
        Assert.AreEqual(2, finonacci.Recursive(3));
        Assert.AreEqual(3, finonacci.Recursive(4));
        Assert.AreEqual(5, finonacci.Recursive(5));
        Assert.AreEqual(8, finonacci.Recursive(6));
        Assert.AreEqual(13, finonacci.Recursive(7));
        Assert.AreEqual(21, finonacci.Recursive(8));
    }

    [TestMethod]
    public void Test2()
    {
        var sw = new Stopwatch();
        sw.Start();
        var f50 = finonacci.DynamicProgramming(50);
        sw.Stop();
        Console.WriteLine($"Time consumed: {sw.Elapsed.TotalSeconds}");

        Assert.AreEqual(12586269025, f50);
    }

    [TestMethod]
    public void Test3()
    {
        var sw = new Stopwatch();
        sw.Start();
        var f50 = finonacci.Iterate(50);
        sw.Stop();
        Console.WriteLine($"Time consumed: {sw.Elapsed.TotalSeconds}");

        Assert.AreEqual(12586269025, f50);
    }
}