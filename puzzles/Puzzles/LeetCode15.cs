namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/3sum/
/// </summary>
public class LeetCode15
{
    public IList<IList<int>> Solve(int[] numbers)
    {
        if (numbers == null || numbers.Length < 3)
            throw new ArgumentException("The input array doesn't meet the constraints.");

        Array.Sort<int>(numbers);

        var triplets = new List<IList<int>>();
        for (var first = 0; first < numbers.Length - 2; first++)
        {
            if (numbers[first] > 0) return triplets;
            if (first > 0 && numbers[first] == numbers[first - 1]) continue;

            var target = 0 - numbers[first];
            var second = first + 1;
            var third = numbers.Length - 1;
            if (numbers[second] > target / 2 || numbers[third] < 0) break;

            while (second < third)
            {
                if (numbers[second] + numbers[third] < target)
                    second++;
                else if (numbers[second] + numbers[third] > target)
                    third--;
                else
                {
                    triplets.Add(new List<int> { numbers[first], numbers[second], numbers[third] });
                    second++;
                    third--;
                    while (second < third && numbers[second] == numbers[second - 1]) second++;
                    while (third > second && numbers[third] == numbers[third + 1]) third--;
                }
            }
        }

        return triplets;
    }
}