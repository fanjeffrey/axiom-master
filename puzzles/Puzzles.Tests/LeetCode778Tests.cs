using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

[TestClass]
public class LeetCode778Tests
{
    private LeetCode778 leetCode778;

    [TestInitialize]
    public void Setup()
    {
        leetCode778 = new LeetCode778();
    }

    [TestMethod]
    public void Dijkstra_Test1()
    {
        var grid = new int[][] {
            new int[] {0, 1, 2, 3, 4},
            new int[] {24, 23, 22, 21, 5},
            new int[] {12, 13, 14, 15, 16},
            new int[] {11, 17, 18, 19, 20},
            new int[] {10, 9, 8, 7, 6}
        };

        var actual = leetCode778.Dijkstra(grid);

        Assert.AreEqual(16, actual);
    }

    [TestMethod]
    public void Dijkstra_Test2()
    {
        var grid = new int[][] {
            new int[] {0, 10, 20, 30, 40},
            new int[] {240, 230, 220, 210, 50},
            new int[] {120, 130, 140, 150, 160},
            new int[] {110, 170, 180, 190, 200},
            new int[] {100, 90, 80, 70, 60}
        };

        var actual = leetCode778.Dijkstra(grid);

        Assert.AreEqual(160, actual);
    }

    [TestMethod]
    public void Dijkstra_Test3()
    {
        var grid = new int[][] {
            new int[] {0,   10,     20,     30,     40},
            new int[] {240, 230,    220,    210,    50},
            new int[] {120, 130,    140,    150,    999},
            new int[] {110, 170,    180,    190,    200},
            new int[] {100, 90,     80,     70,     60}
        };

        var actual = leetCode778.Dijkstra(grid);

        Assert.AreEqual(210, actual);
    }

    [TestMethod]
    public void BreadthFirstSearchAndBinarySearch_Test1()
    {
        var grid = new int[][] {
            new int[] {0, 1, 2, 3, 4},
            new int[] {24, 23, 22, 21, 5},
            new int[] {12, 13, 14, 15, 16},
            new int[] {11, 17, 18, 19, 20},
            new int[] {10, 9, 8, 7, 6}
        };

        var actual = leetCode778.BreadthFirstSearchAndBinarySearch(grid);

        Assert.AreEqual(16, actual);
    }

    [TestMethod]
    public void BreadthFirstSearchAndBinarySearch_Test2()
    {
        var grid = new int[][] {
            new int[] {0,   10,     20,     30,     40},
            new int[] {240, 230,    220,    210,    50},
            new int[] {120, 130,    140,    150,    160},
            new int[] {110, 170,    180,    190,    200},
            new int[] {100, 90,     80,     70,     60}
        };

        var actual = leetCode778.BreadthFirstSearchAndBinarySearch(grid);

        Assert.AreEqual(160, actual);
    }
}
