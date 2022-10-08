namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/fibonacci-number/
/// </summary>
public class Fibonacci
{
    public long Recursive(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return Recursive(n - 1) + Recursive(n - 2);
    }

    private long[] _store = new long[51];
    public long DynamicProgramming(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        if (_store[n] != 0) return _store[n];

        _store[n] = DynamicProgramming(n - 1) + DynamicProgramming(n - 2);

        return _store[n];
    }

    public long Iterate(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        var prev2 = 0L;
        var prev1 = 1L;
        var current = 1L;

        for (var i = 2; i <= n; i++)
        {
            current = prev2 + prev1;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
}