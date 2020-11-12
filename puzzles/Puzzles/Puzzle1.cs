using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace Puzzles
{
    public class Puzzle1
    {
        public string[] Seperators = new string[] { ",", ";", ".", "?", "\r", "\n", " " };

        public void Parse(string slice, Dictionary<string, int> frequencyData)
        {
            if (string.IsNullOrWhiteSpace(slice)) return;

            if (frequencyData == null) frequencyData = new Dictionary<string, int>();

            var words = slice.Split(Seperators, StringSplitOptions.RemoveEmptyEntries);
            foreach (var w in words)
            {
                if (frequencyData.ContainsKey(w.ToLower()))
                    frequencyData[w.ToLower()]++;
                else
                    frequencyData[w.ToLower()] = 1;
            }
        }

        public List<string>[] Sort(Dictionary<string, int> frequencyData)
        {
            var orderedData = new List<string>[frequencyData.Count];

            foreach (var item in frequencyData)
            {
                if (orderedData[item.Value - 1] == null)
                {
                    orderedData[item.Value - 1] = new List<string>();
                }
                orderedData[item.Value - 1].Add(item.Key);
            }

            for (var i = orderedData.Length - 1; i >= 0; i--)
            {
                if (orderedData[i] == null) continue;

                foreach (var word in orderedData[i])
                    Console.WriteLine($"{word} - {i + 1}");
            }

            return orderedData;
        }
    }
}