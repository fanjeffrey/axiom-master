using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace Puzzles.Tests
{
    [TestClass]
    public class LeetCode1987Tests
    {
        [TestMethod]
        public void Test1()
        {
            var input = "101";
            var actual = new LeetCode1987().NumberOfUniqueGoodSubsequences(input);
            Assert.AreEqual(5, actual);
        }

        [TestMethod]
        public void Test2()
        {
            var input = "111";
            var actual = new LeetCode1987().NumberOfUniqueGoodSubsequences(input);
            Assert.AreEqual(3, actual);
        }

        [TestMethod]
        public void Test3()
        {
            var input = "001";
            var actual = new LeetCode1987().NumberOfUniqueGoodSubsequences(input);
            Assert.AreEqual(2, actual);
        }

        [TestMethod]
        public void Test4()
        {
            var input = "00101";
            var actual = new LeetCode1987().NumberOfUniqueGoodSubsequences(input);
            Assert.AreEqual(5, actual);
        }

        [TestMethod]
        public void Test5()
        {
            var input = "000010011";
            var actual = new LeetCode1987().NumberOfUniqueGoodSubsequences(input);
            Assert.AreEqual(10, actual);
        }
    }
}