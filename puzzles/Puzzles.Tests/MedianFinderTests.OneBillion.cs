using System;
using System.IO;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests;

public partial class MedianFinderTests
{
    //[TestMethod]
    public void ShouldBeAverageOfTwoMedians()
    {
        var filePath = @"TestResults/random-numbers-1billion.data";
        var minValue = uint.MinValue;
        var maxValue = uint.MaxValue;
        var median1 = int.MaxValue - 1;
        var median2 = int.MaxValue;
        var billion = 10000 * 10000 * 10;
        GenerateUnsignedIntegers(filePath, median1, median2, billion);
        var expected = ((double)median1 + (double)median2) / 2;

        var actual = _finder.FindMedian(filePath, minValue, maxValue);

        Assert.AreEqual(expected, actual);
    }

    //[TestMethod]
    public void ShouldBeExpectedWhenLengthIsOdd()
    {
        var filePath = @"TestResults/random-numbers-1billion.data";
        var minValue = uint.MinValue;
        var maxValue = uint.MaxValue;
        var median1 = int.MaxValue;
        var billion = 10000 * 10000 * 10 + 1;
        GenerateUnsignedIntegers(filePath, median1, null, billion);
        var expected = median1;

        var actual = _finder.FindMedian(filePath, minValue, maxValue);

        Assert.AreEqual(expected, actual);
    }

    private static void GenerateUnsignedIntegers(string filePath, int median1, int? median2, long lengthOfNumbers)
    {
        using (var stream = new FileStream(filePath, FileMode.Create))
        {
            using (var writer = new BinaryWriter(stream))
            {
                var batchSize = 1000 * 1000;
                var batch = 0;
                while (batch * batchSize < lengthOfNumbers)
                {
                    var numbers = new uint[batchSize];
                    InitUintArray(numbers, median1, median2);
                    if (batch == 0)
                    {
                        numbers[0] = (uint)median1;
                        if (median2.HasValue) numbers[1] = (uint)median2;
                    }
                    WriteToFile(writer, numbers);

                    batch++;
                }

                if (lengthOfNumbers % batchSize != 0)
                {
                    var numbers = new uint[lengthOfNumbers % batchSize];
                    InitUintArray(numbers, median1, median2);
                    WriteToFile(writer, numbers);
                }
            }
        }
    }

    private static void InitUintArray(uint[] numbers, int median1, int? median2)
    {
        median2 = median2 ?? median1;
        var random = new Random();
        for (long i = 0; i < numbers.Length; i++)
        {
            numbers[i] = i % 2 == 0 ? (uint)random.Next(median1 - 1) : (uint)median2 + (uint)random.Next(1, median2.Value - 1);
        }
    }

    private static void WriteToFile(BinaryWriter writer, uint[] numbers)
    {
        var bytes = new byte[numbers.Length * sizeof(uint)];
        Buffer.BlockCopy(numbers, 0, bytes, 0, bytes.Length);
        writer.Write(bytes);
    }
}