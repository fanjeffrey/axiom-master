using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Sorting.Tests;

[TestClass]
public class BinarySearchTests
{
    private BinarySearch _binarySearch;

    [TestInitialize]
    public void Setup()
    {
        _binarySearch = new BinarySearch();
    }

    [TestMethod]
    public void ShouldReturnExpectedIndex()
    {
        int[] array = { 1, 3, 5, 7, 9, 11, 12, 14, 16, 18, 20 };
        var expectedIndex = 4;
        var target = array[expectedIndex];

        var actual = _binarySearch.Find(array, target);

        Assert.AreEqual(expectedIndex, actual);
    }

    [TestMethod]
    public void ShouldWorkWithOneElementArray()
    {
        int[] array = { 1 };
        var expectedIndex = 0;
        var target = array[expectedIndex];

        var actual = _binarySearch.Find(array, target);

        Assert.AreEqual(expectedIndex, actual);
    }

    [TestMethod]
    public void ShouldReturnNegativeOne()
    {
        int[] array = { 1, 3, 5, 7, 9, 11, 12, 14, 16, 18, 20 };
        var expectedIndex = -1;
        var target = int.MaxValue;

        var actual = _binarySearch.Find(array, target);

        Assert.AreEqual(expectedIndex, actual);
    }
}