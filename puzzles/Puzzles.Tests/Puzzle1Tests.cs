using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests
{
    [TestClass]
    public class Puzzle1Tests
    {
        private Puzzle1 _puzzle1;

        [TestInitialize]
        public void Setup()
        {
            _puzzle1 = new Puzzle1();
        }

        [TestMethod]
        public void Parse_Test1()
        {
            // Arrange
            var article = @"
It's been such a strange, lost summer. Camps and schools and activities have shut down during the pandemic, leaving kids and caregivers stuck at home and climbing the walls — and sometimes the garden fences.
With that in mind, we decided that this year's summer reader poll should be all about keeping kids occupied. We asked you to tell us about your favorite kids' books, from board books for babies to great read-alouds to early chapter books and even a few books for older readers. And thousands of you answered.
As with all our summer polls, this one isn't a straight-up popularity contest. (Otherwise it would have been nothing but 100 Mo Willems books — and we love Mo Willems, but that wouldn't have been the most useful list.) Rather, it's a curated list built from your recommendations and picks from our expert panel of judges — a fantastic group of authors, librarians, publishers and all-around book nerds. And instead of a ranked list, it's grouped into categories that we hope will help you find just the right books for the kids in your life.";
            var frequencyData = new Dictionary<string, int>();

            // Act
            _puzzle1.Parse(article, frequencyData);

            // Assert
            Assert.IsNotNull(frequencyData);
            Assert.IsTrue(frequencyData.Keys.Count > 1);
            Assert.IsTrue(frequencyData.Keys.All(k => !string.IsNullOrWhiteSpace(k)));
            Assert.IsTrue(frequencyData.Values.All(v => v > 0));

            // Act
            var orderedFrequencyData = _puzzle1.Sort(frequencyData);
            Assert.IsTrue(frequencyData.Where(kv => kv.Value == 1).All(kv => orderedFrequencyData.First().Contains(kv.Key)));
            Assert.IsTrue(frequencyData.Where(kv => kv.Value == 2).All(kv => orderedFrequencyData[1].Contains(kv.Key)));
        }
    }
}