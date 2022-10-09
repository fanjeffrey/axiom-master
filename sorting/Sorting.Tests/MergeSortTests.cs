using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Sorting.Tests;

[TestClass]
public class MergeSortTests
{
    private MergeSort _mergeSort;

    [TestInitialize]
    public void Setup()
    {
        _mergeSort = new MergeSort();
    }

    [TestMethod]
    public void TestMethod1()
    {
        int[] array = { 10, 33, 2, 4, 5, 123, 43, 28, 29, 12, 16, 15, 19, 77, 39, 77, 101, 100, 86, 33 };

        _mergeSort.Sort(array);

        Assert.IsTrue(array.IsAscending());
    }

    [TestMethod]
    public void TestMethod2()
    {
        int[] array = { 9, 9, 9, 9, 9, 9, 2, 2, 2, 2, 2, 8, 8, 8, 8, 8, 3, 3, 3, 3, 3, 7, 7, 7, 7, 7 };

        _mergeSort.Sort(array);

        Assert.IsTrue(array.IsAscending());
    }

    [TestMethod]
    public void TestMethod3()
    {
        int[] array = { 7, 8, 3, 9, 4, 5, 6 };

        _mergeSort.Sort(array);

        Assert.IsTrue(array.IsAscending());
    }

    [TestMethod]
    public void TestMethod4()
    {
        int[] array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        _mergeSort.Sort(array);

        Assert.IsTrue(array.IsAscending());
    }

    [TestMethod]
    public void TestMethod5()
    {
        int[] array = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

        _mergeSort.Sort(array);

        Assert.IsTrue(array.IsAscending());
    }
}