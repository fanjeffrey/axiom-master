using System;
using System.Diagnostics;
using System.IO;

namespace Puzzles
{
    public class UintMedianFinderDemo
    {
        public void DemoWith1BillionData()
        {
            // Arrange
            var billion = 10000 * 10000 * 10;
            var maxAvailableMemoryInMB = 1024;
            var filePath = @"random-numbers-1billion.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            var expectedMedian = maxValue / 2;
            GenerateUintFile(filePath, expectedMedian, billion);

            var median = new UintMedianFinder(maxAvailableMemoryInMB).FindMedian(filePath, minValue, maxValue);

            Console.WriteLine($"the median is: {median}");
        }

        private static void GenerateUintFile(string filePath, uint expectedMedian, long lengthOfNumbers)
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
                        InitUintArray(numbers);
                        if (batch == 0) numbers[0] = expectedMedian;
                        WriteToFile(writer, numbers);

                        batch++;
                    }

                    if (lengthOfNumbers % batchSize != 0)
                    {
                        var numbers = new uint[lengthOfNumbers % batch];
                        InitUintArray(numbers);
                        WriteToFile(writer, numbers);
                    }
                }
            }
        }

        private static void InitUintArray(uint[] numbers)
        {
            var random = new Random();
            for (long i = 0; i < numbers.Length; i++)
            {
                numbers[i] = i % 2 == 0 ? (uint)random.Next() : int.MaxValue + (uint)random.Next();
            }
        }

        private static void WriteToFile(BinaryWriter writer, uint[] numbers)
        {
            var bytes = new byte[numbers.Length * sizeof(uint)];
            Buffer.BlockCopy(numbers, 0, bytes, 0, bytes.Length);
            writer.Write(bytes);
        }
    }

    public class UintMedianFinder
    {
        private const int DefaultMemoryLimitInMB = 1024;
        private const int OneMB = 1024 * 1024;
        private const int BytesForInteger = 4;

        public int MemoryLimitInBytes { get; private set; }
        public int MaxCountOfIntegersPerBatch { get; private set; }

        public UintMedianFinder(int memoryLimitInMB)
        {
            if (memoryLimitInMB <= 1 || memoryLimitInMB > 1024) throw new ArgumentException(nameof(memoryLimitInMB));

            MemoryLimitInBytes = memoryLimitInMB * OneMB;

            MaxCountOfIntegersPerBatch = CalculateBatchSize();
        }

        public double FindMedian(string filePath, uint minValue, uint maxValue)
        {
            if (filePath == null) throw new ArgumentNullException(nameof(filePath));

            var partitions = FindMedianPartitions(filePath, minValue, maxValue);

            var median = partitions.Length switch
            {
                1 => FindMedianWithinPartition(filePath, partitions[0]),
                2 => (FindMedianWithinPartition(filePath, partitions[0]) + FindMedianWithinPartition(filePath, partitions[1], true)) / 2.0d,
                _ => throw new Exception("Oops! Something's beyond your thoughts.")
            };

            return median;
        }

        private Partition[] FindMedianPartitions(string filePath, uint minValue, uint maxValue)
        {
            using (var stream = new FileStream(filePath, FileMode.Open))
            {
                using (var reader = new BinaryReader(stream))
                {
                    var rawPartitions = new Partitions(minValue, maxValue);

                    while (stream.Position < stream.Length)
                    {
                        var bytes = reader.ReadBytes(MaxCountOfIntegersPerBatch);
                        for (var i = 0; i < bytes.Length; i += 4)
                        {
                            rawPartitions.Counting(BitConverter.ToUInt32(bytes, i));
                        }
                        bytes = null;
                    }

                    long countOfIntegers = stream.Length / 4;
                    long medianPosition = CalculateMedianPosition(countOfIntegers);

                    var median1Partition = rawPartitions.GetPartition(medianPosition);
                    if (countOfIntegers % 2 == 0)
                    {
                        var median2Partition = rawPartitions.GetPartition(medianPosition + 1);

                        return new Partition[] { median1Partition, median2Partition };
                    }
                    else
                    {
                        return new Partition[] { median1Partition };
                    }
                }
            }
        }

        private int CalculateBatchSize()
        {
            var maxMemoryUsedToReadIntegers = MemoryLimitInBytes / 2;

            return maxMemoryUsedToReadIntegers / BytesForInteger;
        }

        private double FindMedianWithinPartition(string filePath, Partition partition, bool isMedian2 = false)
        {
            using (var stream = new FileStream(filePath, FileMode.Open))
            {
                using (var reader = new BinaryReader(stream))
                {
                    var partitions = new Partitions(partition.StartValue, partition.EndValue, 1);

                    while (stream.Position < stream.Length)
                    {
                        var bytes = reader.ReadBytes(MaxCountOfIntegersPerBatch);
                        for (var i = 0; i < bytes.Length; i += 4)
                        {
                            var theInteger = BitConverter.ToUInt32(bytes, i);
                            if (partition.StartValue <= theInteger && theInteger <= partition.EndValue)
                                partitions.Counting(theInteger - partition.StartValue);
                        }
                        bytes = null;
                    }

                    long medianPosition = CalculateMedianPosition(stream.Length / 4);
                    if (isMedian2) medianPosition++;
                    long countingTo = medianPosition - partition.CountingFrom;

                    var median = partitions.GetPartition(countingTo).StartValue + partition.StartValue;
                    Debug.WriteLine($"median: {median}");

                    return median;
                }
            }
        }

        static private long CalculateMedianPosition(long countOfNumbers)
        {
            // if the count of integers is 9, then the median position is 5
            // if the count of integers is 10, then the median positions are 5, and 6;
            return (countOfNumbers + 1) / 2L;
        }

        public double FindMedian(uint[] numbers)
        {
            const int MaxCount = 20 * 10000;
            if (numbers.Length > MaxCount) throw new ArgumentException($"The array {nameof(numbers)} is too large. The uppper limit is {MaxCount}.");

            Array.Sort<uint>(numbers);
            var middlePosition = (numbers.Length - 1) / 2;

            return (numbers.Length % 2 == 0) ? (numbers[middlePosition] + numbers[middlePosition + 1]) / 2.0d : numbers[middlePosition];
        }
    }

    public class Partitions
    {
        private const int PartitionSizeDefaultValue = 10000 * 10;

        public long Count => _partitions.Length;

        private readonly long _minValue;
        private readonly long _maxValue;
        private readonly int _partitionSize;
        private readonly long[] _partitions;

        public Partitions(long minValue, long maxValue, int partitionSize = PartitionSizeDefaultValue)
        {
            _minValue = minValue;
            _maxValue = maxValue;
            _partitionSize = partitionSize <= 0 ? PartitionSizeDefaultValue : partitionSize;
            _partitions = new long[CalculateBucketNumbers()];
        }

        public void Counting(uint theValue)
        {
            _partitions[theValue / _partitionSize]++;
        }

        public Partition GetPartition(long countingTo)
        {
            long sumOfCounting = 0;
            var i = 0;
            for (i = 0; i < _partitions.Length; i++)
            {
                if (sumOfCounting + _partitions[i] >= countingTo) break;
                sumOfCounting += _partitions[i];
            }

            return new Partition(i, _partitionSize, sumOfCounting);
        }

        private long CalculateBucketNumbers()
        {
            long totalNumbers = _maxValue - _minValue + 1;
            return totalNumbers % _partitionSize == 0
                ? totalNumbers / (long)_partitionSize
                : totalNumbers / (long)_partitionSize + 1; // "+ 1" means we need one more partition to hold the remainder
        }
    }

    public class Partition
    {
        public Partition(int no, int size, long countingFrom)
        {
            No = no;
            Size = size;
            CountingFrom = countingFrom;
        }

        public int No { get; set; }
        public int Size { get; set; }
        public long CountingFrom { get; set; }
        public uint StartValue => (uint)(No * Size);
        public uint EndValue => ((No + 1L) * Size - 1) > uint.MaxValue ? uint.MaxValue : (uint)((No + 1L) * Size - 1);
    }
}