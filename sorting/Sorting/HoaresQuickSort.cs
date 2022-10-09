namespace Sorting;

public class HoaresQuickSort
{
    public void Sort(int[] array)
    {
        Sort(array, 0, array.Length - 1);
    }

    public void Sort(int[] array, int start, int end)
    {
        if (start >= end) return;

        var partitionIndex = Partition(array, start, end);
        Sort(array, start, partitionIndex);
        Sort(array, partitionIndex + 1, end);
    }

    private int Partition(int[] array, int start, int end)
    {
        // 7, 8, 3, 9, 4, 5, 6
        // pivot = 7; head = -1; tail = 7
        // head++ = 0; array[0] = 7; 7 < 7 = false, exit do-while
        // tail-- = 6; array[6] = 6; 6 > 7 = false, exit do-while
        // head >= tail = false, swap array[0] and array[6]
        // 6, 8, 3, 9, 4, 5, 7
        // head++ = 1; array[1] = 8; 8 < 7 = false, exit do-while
        // tail-- = 5; array[5] = 5; 5 > 7 = false, exit do-while
        // head >= tail = false, swap array[1] and array[5]
        // 6, 5, 3, 9, 4, 8, 7
        // head++ = 2; array[2] = 3; 3 < 7 = true
        // head++ = 3; array[3] = 9; 9 < 7 = false, exit do-while
        // tail-- = 4; array[4] = 4; 4 > 7 = false, exit do-while
        // head >= tail = false, swap array[3] and array[4]
        // 6, 5, 3, 4, 9, 8, 7
        // head++ = 4; array[4] = 9; 9 < 7 = false, exit do-while
        // tail-- = 3; array[3] = 4; 4 > 7 = false, exit do-while
        // head >= tail = true, return tail(=3), so the array is splitted into two partitions:
        // left: array[0]~array[3] < pivot(=7)
        // right: array[3+1]~array[6] >= pivot(=7)

        // set pivot = the first element
        // set two pointers: head and tail
        // find the leftmost element which >= the pivot,
        // find the rightmost element which <= the pivot,
        // if tow pointers meet, return tail as partition index
        // otherwise swap the elements at head and tail.
        var pivot = array[start];
        var head = start - 1;
        var tail = end + 1;

        while (true)
        {
            do { head++; } while (array[head] < pivot);
            do { tail--; } while (array[tail] > pivot);

            if (head >= tail) return tail;
            Swap(array, head, tail);
        }
    }

    private void Swap(int[] array, int i, int j)
    {
        var temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
