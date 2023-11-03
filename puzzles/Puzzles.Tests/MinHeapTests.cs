using System;
using System.Diagnostics;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class MinHeapTests
{
    private MinHeap minHeap;

    [TestInitialize]
    public void Setup()
    {
        minHeap = new MinHeap(1000);
    }

    [TestMethod]
    public void Test1()
    {
        var numbers = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        foreach (var n in numbers) minHeap.Put(n);

        Assert.AreEqual(numbers.Length, minHeap.Size);
        for (var i = 0; i < numbers.Length; i++)
        {
            Assert.AreEqual(numbers[i], minHeap.Pop());
        }
    }

    [TestMethod]
    public void Test2()
    {
        var numbers = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        for (var i = numbers.Length - 1; i >= 0; i--) minHeap.Put(numbers[i]);

        Assert.AreEqual(numbers.Length, minHeap.Size);
    }
}

public class MinHeap
{
    public int Size { get; private set; }

    public MinHeap(int capacity)
    {
        _array = new int[capacity];

        Size = 0;
    }

    public void Put(int n)
    {
        var ci = Size;
        _array[Size++] = n;

        while (ci > 0)
        {
            var pi = (ci - 1) / 2;
            if (_array[ci] < _array[pi]) Swap(_array, ci, pi);
            ci = pi;
        }

        Debug.WriteLine(string.Join(" ", _array.Take(Size)));
    }

    public int Pop()
    {
        if (Size <= 0)
        {
            throw new InvalidOperationException("No elements in the heap.");
        }

        var top = _array[0];
        _array[0] = _array[--Size];

        Debug.WriteLine(string.Join(" ", _array.Take(Size)));

        var pi = 0;
        while (pi <= (Size - 1) / 2)
        {
            var lci = pi * 2 + 1;
            var rci = pi * 2 + 2;
            if (_array[pi] < _array[lci] && _array[pi] < _array[rci]) break;

            if (_array[lci] < _array[rci])
            {
                Swap(_array, lci, pi);
                pi = lci;
            }
            else
            {
                Swap(_array, rci, pi);
                pi = rci;
            }

            Debug.WriteLine(string.Join(" ", _array.Take(Size)));
        }

        return top;
    }

    private static void Swap(int[] array, int ci, int pi)
    {
        var temp = array[ci];
        array[ci] = array[pi];
        array[pi] = temp;
    }

    private readonly int[] _array;
}
