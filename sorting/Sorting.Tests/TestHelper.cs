namespace Sorting.Tests;

public static class TestHelper
{
    public static bool IsAscending(this int[] array)
    {
        for (var i = 1; i < array.Length; i++) if (array[i-1] > array[i]) return false;

        return true;
    }
}