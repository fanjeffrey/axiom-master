using System;
using System.IO;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests
{
    [TestClass]
    public partial class MedianFinderTests
    {
        private UintMedianFinder _finder;

        [TestInitialize]
        public void Setup()
        {
            _finder = new UintMedianFinder(1024);
        }

        [TestMethod]
        public void FindMedian_ShouldReturnTheOnly()
        {
            // arrange
            var sources = new uint[] { 8 };

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual(sources[0], median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [DataTestMethod]
        [DataRow(0u, 99999u)]
        [DataRow(8u, 9u)]
        public void FindMedian_ShouldReturnTheAverage_WhenOnly2NumbersWithinTheSamePartition(uint value1, uint value2)
        {
            // arrange
            var sources = new uint[] { value1, value2 };

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual((value1 + value2) / 2.0, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [DataTestMethod]
        [DataRow(uint.MinValue, uint.MaxValue)]
        [DataRow(8u, 9u + 10000u * 10u)]
        public void FindMedian_ShouldReturnTheAverage_When2NumbersWithinDifferentPartition(uint value1, uint value2)
        {
            // arrange
            var sources = new uint[] { value1, value2 };

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual((value1 + value2) / 2.0, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [TestMethod]
        public void FindMedian_ShouldReturnTheMedian()
        {
            // arrange
            var sources = new uint[] { 1, 10, 20, 5, 7, 8, 9, 4, 11, 12 };

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual((8 + 9) / 2.0, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [TestMethod]
        public void FindMedian_ShouldReturnTheMedian_WhenTheLengthOfNumbersIsOdd()
        {
            // arrange
            var sources1 = new uint[] { 1, 10, 20, 5, 7, 8, 9, 4, 11, 12 };
            var sources2 = new uint[] { 2, 2, 2, 2, 2 };
            var all = sources1.Concat(sources2).ToArray();

            // act
            var median = _finder.FindMedian(all);

            // assert
            Assert.AreEqual(5, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, all);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [TestMethod]
        public void FindMedian_ShouldReturnTheMedian_WhenAllNumbersAreSameAndTheLengthIsOdd()
        {
            // arrange
            var sources = new uint[] { 2, 2, 2, 2, 2, 2, 2, 2, 2 };

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual(2, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        [DataTestMethod]
        [DataRow(2u)]
        [DataRow(100 * 10000u)]
        public void FindMedian_ShouldReturnTheMedian_WhenAllNumbersAreSameAndTheLengthIsEven(uint theInteger)
        {
            // arrange
            var sources = new uint[10];
            for (int i = 0; i < sources.Length; i++)
            {
                sources[i] = theInteger;
            }

            // act
            var median = _finder.FindMedian(sources);

            // assert
            Assert.AreEqual(theInteger, median);

            // Arrange
            var filePath = @"random-numbers.data";
            var minValue = uint.MinValue;
            var maxValue = uint.MaxValue;
            GenerateFile(filePath, sources);

            // Act
            var median2 = _finder.FindMedian(filePath, minValue, maxValue);

            // Assert
            Assert.AreEqual(median, median2);
        }

        private static void GenerateFile(string filePath, uint[] integers)
        {
            using (var stream = new FileStream(filePath, FileMode.Create))
            {
                using (var writer = new BinaryWriter(stream))
                {
                    var bytes = new byte[integers.Length * sizeof(uint)];
                    Buffer.BlockCopy(integers, 0, bytes, 0, bytes.Length);
                    writer.Write(bytes);
                }
            }
        }
    }
}
