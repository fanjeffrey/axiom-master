namespace Sorting;

public class LomutosQuickSort
{
    public void Sort(int[] array)
    {
        Sort(array, 0, array.Length - 1);
    }

    public void Sort(int[] array, int start, int end)
    {
        if (start >= end) return;

        var partitionIndex = Partition(array, start, end);
        Sort(array, start, partitionIndex - 1);
        Sort(array, partitionIndex + 1, end);
    }

    private int Partition(int[] array, int start, int end)
    {
        // 7, 8, 3, 9, 4, 5, 6
        // pivot = 6; partitionIndex = 0; j = 0; array[0] = 7
        // pivot = 6; partitionIndex = 0; j = 1; array[1] = 8
        // pivot = 6; partitionIndex = 0; j = 2; array[2] = 3; swapping 3 and 7; partitionIndex = 1
        // 3, 8, 7, 9, 4, 5, 6
        // pivot = 6; partitionIndex = 1; j = 3; array[3] = 9
        // pivot = 6; partitionIndex = 1; j = 4; array[4] = 4; swapping 4 and 8; partitionIndex = 2
        // 3, 4, 7, 9, 8, 5, 6
        // pivot = 6; partitionIndex = 2; j = 5; array[5] = 5; swapping 5 and 7; partitionIndex = 3
        // 3, 4, 5, 9, 8, 7, 6
        // pivot = 6; partitionIndex = 3; j = 6; exit loop
        // pivot = 6; partitionIndex = 3; swap 6 and 9
        // 3, 4, 5, 6, 8, 7, 9
        // return partitionIndex (=3)

        // set pivot = the last element
        // set partitionIndex = the start position
        // If all elements before the end position > the pivot, no swapping occurs in the loop, the pivot will be swapped to the start position after the loop.
        // If some element <= the pivot, then move it ahead by swapping, the pivot will be swapped to the partition index after the loop.
        var pivot = array[end];
        var partitionIndex = start;

        for (var j = start; j < end; j++)
        {
            if (array[j] <= pivot)
            {
                Swap(array, partitionIndex, j);
                partitionIndex++;
            }
        }

        Swap(array, partitionIndex, end);

        return partitionIndex;
    }

    private void Swap(int[] array, int i, int j)
    {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}