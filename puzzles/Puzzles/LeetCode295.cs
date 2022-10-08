namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/find-median-from-data-stream/
/// </summary>
public class LeetCode295
{
    // to hold those numbers <= median
    private readonly PriorityQueue<int, int> _left;

    // to hold those numbers > median
    private readonly PriorityQueue<int, int> _right;

    private int Count => _left.Count + _right.Count;

    public LeetCode295()
    {
        _left = new PriorityQueue<int, int>();
        _right = new PriorityQueue<int, int>();
    }

    public void AddNum(int number)
    {
        if (_left.Count == 0 || number <= _left.Peek())
        {
            _left.Enqueue(number, -number);
        }
        else
        {
            _right.Enqueue(number, number);
        }

        BalanceLeftAndRight();
    }

    public double FindMedian()
    {
        var possibleMedian = _left.Peek();
        return (_left.Count == _right.Count) ? (possibleMedian + _right.Peek()) / 2d : possibleMedian;
    }

    private void BalanceLeftAndRight()
    {
        if (_left.Count - 1 > _right.Count)
        {
            var temp = _left.Dequeue();
            _right.Enqueue(temp, temp);
        }
        else if (_left.Count < _right.Count)
        {
            var temp = _right.Dequeue();
            _left.Enqueue(temp, -temp);
        }
    }
}