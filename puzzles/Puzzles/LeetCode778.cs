namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/swim-in-rising-water/
/// </summary>
public class LeetCode778
{
    public int Dijkstra(int[][] grid)
    {
        var n = grid.Length;
        var queue = new PriorityQueue<(int X, int Y), int>();
        queue.Enqueue((0, 0), grid[0][0]);
        var visited = new bool[n, n];
        visited[0, 0] = true;

        int elevation;
        while (queue.TryDequeue(out var cell, out elevation))
        {
            if (cell.X == n - 1 && cell.Y == n - 1) break;

            for (var i = 0; i < Directions.Length - 1; i++)
            {
                var newX = cell.X + Directions[i];
                var newY = cell.Y + Directions[i + 1];
                if (newX < 0 || newX >= n || newY < 0 || newY >= n || visited[newX, newY]) continue;

                visited[newX, newY] = true;
                queue.Enqueue((newX, newY), Math.Max(elevation, grid[newX][newY]));
            }
        }

        return elevation;
    }

    public int BreadthFirstSearchAndBinarySearch(int[][] grid)
    {
        var n = grid.Length;
        var l = 0;
        var r = n * n;
        while (l < r)
        {
            var m = l + (r - l) / 2;
            if (ExistPath(grid, m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return grid[l / n][l % n];
    }

    static private bool ExistPath(int[][] grid, int cell)
    {
        var n = grid.Length;
        var queue = new Queue<int>();
        queue.Enqueue(0);
        var visited = new bool[n * n];
        visited[0] = true;

        while (queue.TryDequeue(out var position))
        {
            var x = position / n;
            var y = position % n;

            if (x == n - 1 && y == n - 1) return true;

            for (var i = 0; i < Directions.Length - 1; i++)
            {
                var newX = x + Directions[i];
                var newY = y + Directions[i + 1];
                var newPosition = newX * n + newY;
                if (newX < 0 || newX >= n || newY < 0 || newY >= n
                    || visited[newPosition]
                    || grid[newX][newY] > grid[cell / n][cell % n]) continue;

                visited[newPosition] = true;
                queue.Enqueue(newPosition);
            }
        }

        return false;
    }

    private static int[] Directions = { -1, 0, 1, 0, -1 };
}