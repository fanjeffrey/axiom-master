namespace Sorting;

public class BinarySearch
{
    public int Find(int[] array, int target)
    {
        return Find(array, 0, array.Length - 1, target);
    }

    public int Find(int[] array, int start, int end, int target)
    {
        while (start <= end)
        {
            var mid = start + (end - start) / 2;
            if (target == array[mid])
            {
                return mid;
            }
            else if (target < array[mid])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return -1;
    }
}