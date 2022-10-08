namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/longest-increasing-subsequence/
/// </summary>
public class LeetCode300
{
    public int Solve(int[] numbers)
    {
        if (numbers == null || numbers.Length <= 0) return 0;

        var list = new List<int> { numbers[0] };

        for (var i = 1; i < numbers.Length; i++)
        {
            BuildLIS(list, numbers[i]);
            // System.Diagnostics.Debug.WriteLine(string.Join(",", list));
        }

        return list.Count;
    }

    private void BuildLIS(List<int> list, int target)
    {
        if (target > list[list.Count - 1]) { list.Add(target); return; }
        if (target < list[0]) { list[0] = target; return; }

        var left = 0;
        var right = list.Count - 1;

        while (left <= right)
        {
            var middle = (left + right) / 2;
            if (list[middle] < target)
                left = middle + 1;
            else if (list[middle] > target)
                right = middle - 1;
            else return;
        }

        list[left] = target;
    }

    public int SovleWithTabulation(int[] numbers)
    {
        if (numbers == null || numbers.Length <= 0) return 0;

        var lengthArray = new int[numbers.Length];
        var maxLength = lengthArray[0] = 1;

        for (var i = 1; i < numbers.Length; i++)
        {
            lengthArray[i] = 1;
            for (var j = 0; j < i; j++)
            {
                if (numbers[i] > numbers[j] && lengthArray[i] < lengthArray[j] + 1)
                    lengthArray[i] = lengthArray[j] + 1;
            }

            if (maxLength < lengthArray[i]) maxLength = lengthArray[i];
        }

        return maxLength;
    }

    public int SolveWithMemoization(int[] numbers)
    {
        if (numbers == null || numbers.Length == 0) return 0;

        _store = new int[numbers.Length + 1];

        int maxLength = 1;

        Memoization(numbers, numbers.Length, ref maxLength);

        return maxLength;
    }

    private int[] _store;
    private int Memoization(int[] numbers, int lengthOfNumbers, ref int maxLength)
    {
        if (lengthOfNumbers == 1) return 1;

        if (_store[lengthOfNumbers] != 0) return _store[lengthOfNumbers];

        var currentLength = 1;

        for (var len = 1; len < lengthOfNumbers; len++)
        {
            _store[len] = Memoization(numbers, len, ref maxLength);
            if (numbers[len - 1] < numbers[lengthOfNumbers - 1])
                currentLength = Math.Max(_store[len] + 1, currentLength);
        }

        if (maxLength < currentLength) maxLength = currentLength;

        return currentLength;
    }

    public int SolveWithRecursion(int[] numbers)
    {
        if (numbers == null || numbers.Length == 0) return 0;

        int maxLength = 1;

        Recursion(numbers, numbers.Length, ref maxLength);

        return maxLength;
    }

    private int Recursion(int[] numbers, int lengthOfNumbers, ref int maxLength)
    {
        if (lengthOfNumbers == 1) return 1;

        var currentLength = 1;

        for (var len = 1; len < lengthOfNumbers; len++)
        {
            var length = Recursion(numbers, len, ref maxLength);
            if (numbers[len - 1] < numbers[lengthOfNumbers - 1])
                currentLength = Math.Max(length + 1, currentLength);
        }

        if (maxLength < currentLength) maxLength = currentLength;

        return currentLength;
    }
}