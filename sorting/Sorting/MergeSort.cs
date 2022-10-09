namespace Sorting;

public class MergeSort
{
    public void Sort(int[] array)
    {
        Sort(array, 0, array.Length - 1);
    }

    public void Sort(int[] array, int start, int end)
    {
        if (start >= end) return;

        var mid = start + (end - start) / 2;
        Sort(array, start, mid);
        Sort(array, mid + 1, end);
        Merge(array, start, mid, end);
    }

    private void Merge(int[] array, int start, int mid, int end)
    {
        var leftLength = mid - start + 1;
        var rightLength = end - mid;
        var leftPart = new int[leftLength];
        var rightPart = new int[rightLength];
        for (var i = 0; i < leftLength; i++)
            leftPart[i] = array[start + i];
        for (var j = 0; j < rightLength; j++)
            rightPart[j] = array[mid + 1 + j];

        var k = start;
        var l = 0;
        var r = 0;
        while (l < leftLength && r < rightLength)
        {
            if (leftPart[l] <= rightPart[r])
            {
                array[k++] = leftPart[l++];
            }
            else
            {
                array[k++] = leftPart[r++];
            }
        }

        while (l < leftLength)
            array[k++] = leftPart[l++];

        while (r < rightLength)
            array[k++] = leftPart[r++];
    }
}