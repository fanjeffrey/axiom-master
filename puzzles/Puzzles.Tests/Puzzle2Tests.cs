using System;
using System.IO;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests
{
    [TestClass]
    public class Puzzle2Tests
    {
        private Puzzle2 _puzzle2;

        [TestInitialize]
        public void Setup()
        {
            _puzzle2 = new Puzzle2();
        }

        [TestMethod]
        public void ShouldReturnTrue()
        {
            // Arrange
            var path = new int[] { 0, 1, 3, 5, 6, 8, 11, 15 };

            // Act
            var result = _puzzle2.Solve(path);

            // Assert
            Assert.IsTrue(result);
        }

        [TestMethod]
        public void ShouldReturnFalse_WhenStepsIsOutOfRange()
        {
            // Arrange
            var path = new int[] { 0, 1, 3, 5, 6, 8, 12, 15 };

            // Act
            var result = _puzzle2.Solve(path);

            // Assert
            Assert.IsFalse(result);
        }

        [TestMethod]
        public void ShouldReturnFalse_WhenGoingBackward()
        {
            // Arrange
            var path = new int[] { 0, 1, 3, 5, 6, 8, 11, 9 };

            // Act
            var result = _puzzle2.Solve(path);

            // Assert
            Assert.IsFalse(result);
        }
    }
}