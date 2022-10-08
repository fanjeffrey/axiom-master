namespace Puzzles;

/// <summary>
/// https://leetcode.com/problems/4sum/
/// </summary>
public class LeetCode18
{
    public IList<IList<int>> Solve(int[] numbers, long target)
    {
        var quadruplets = new List<IList<int>>();

        if (numbers == null || numbers.Length < 4) return quadruplets;

        Array.Sort<int>(numbers);

        if (numbers[numbers.Length - 1] < target / 4) return quadruplets;

        for (var first = 0; first < numbers.Length - 3; first++)
        {
            if (numbers[first] > target / 4) break;
            if (first > 0 && numbers[first] == numbers[first - 1]) continue;

            for (var second = first + 1; second < numbers.Length - 2; second++)
            {
                if (numbers[second] > (target - numbers[first]) / 3) break;
                if (second > first + 1 && numbers[second] == numbers[second - 1]) continue;

                var subTarget = target - numbers[first] - numbers[second];
                var third = second + 1;
                var fourth = numbers.Length - 1;
                while (third < fourth && numbers[third] <= subTarget / 2 && numbers[fourth] >= subTarget / 2)
                {
                    if (numbers[third] + numbers[fourth] < subTarget)
                        third++;
                    else if (numbers[third] + numbers[fourth] > subTarget)
                        fourth--;
                    else
                    {
                        quadruplets.Add(new List<int> { numbers[first], numbers[second], numbers[third], numbers[fourth] });
                        third++;
                        fourth--;
                        while (third < fourth && numbers[third] == numbers[third - 1]) third++;
                        while (fourth > third && numbers[fourth] == numbers[fourth + 1]) fourth--;
                    }
                }
            }
        }

        return quadruplets;
    }

    public IList<IList<int>> FourSum(int[] numbers, long target)
    {
        if (numbers == null || numbers.Length < 4) return new List<IList<int>>();

        Array.Sort<int>(numbers);

        if (numbers[0] > target / 4 || numbers[numbers.Length - 1] < target / 4) return new List<IList<int>>();

        return KSum(numbers, 0, 4, target);
    }

    private static IList<IList<int>> KSum(int[] numbers, int startIndex, int k, long target)
    {
        if (k <= 1) throw new ArgumentException("The value of k must be greater than 1.");

        if (k == 2)
        {
            return TowSumWithSortedArray(numbers, startIndex, target);
        }

        var all = new List<IList<int>>();
        for (var i = startIndex; i < numbers.Length - k + 1; i++)
        {
            if (numbers[i] > target / k) break;
            if (i > startIndex && numbers[i] == numbers[i - 1]) continue;

            all.AddRange(
                KSum(numbers, i + 1, k - 1, target - numbers[i])
                .Select(r => { r.Insert(0, numbers[i]); return r; })
            );
        }

        return all;
    }

    private static List<IList<int>> TowSumWithSortedArray(int[] numbers, int startIndex, long target)
    {
        var couplets = new List<IList<int>>();

        var head = startIndex;
        var tail = numbers.Length - 1;
        var halfTarget = target / 2;

        while (head < tail && numbers[head] <= halfTarget && numbers[tail] >= halfTarget)
        {
            if (numbers[head] + numbers[tail] < target)
            {
                head++;
            }
            else if (numbers[head] + numbers[tail] > target)
            {
                tail--;
            }
            else
            {
                couplets.Add(new List<int> { numbers[head], numbers[tail] });
                head++;
                tail--;
                while (head < tail && numbers[head] == numbers[head - 1]) head++;
                while (tail > head && numbers[tail] == numbers[tail + 1]) tail--;
            }
        }

        return couplets;
    }
}