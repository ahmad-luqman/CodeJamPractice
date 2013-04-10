using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2012QR_RecycledNumbers_cs
{
    class App
    {
        public string[] RecycledPairs(string original)
        {
            //string[] recycledPairs = new string[original.Length];
            IList<string> recycledPairs = new List<string>();
            for (int i = 1; i < original.Length; i++)
            {
                //if (i == 0)
                //    continue; //recycledPairs[i] = original;
                //else
                string possiblePair = original.Substring(i) + original.Substring(0, i);
                if(Convert.ToInt32(possiblePair) > Convert.ToInt32(original))
                    recycledPairs.Add(possiblePair);

            }
            return recycledPairs.ToArray<string>();
        }

        public void Run()
        {
            string input = Console.ReadLine();
            int T = Convert.ToInt32(input);

            for (int t = 0; t < T; t++)
            {
                var str = Console.ReadLine();
                string[] sArray = str.Split(null);

                string sA = sArray[0];
                string sB = sArray[1];
                int A = Convert.ToInt32(sA);
                int B = Convert.ToInt32(sB);

                int y = 0;
                for (int i = A; i < B; i++)
                {
                    string[] pairs = RecycledPairs(i.ToString());
                    foreach (var pair in pairs)
                    {
                        if (Convert.ToInt32(pair) <= B)
                            y++;
                    }
                }

                var output = "Case #{0}: " + y;
                Console.WriteLine(output, t + 1);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var app = new App();

            //using (StreamWriter writer = new StreamWriter("C:\\out.txt"))
            //using (StreamReader reader = new StreamReader(@"B-large-practice.in"))
            {
                //Console.SetOut(writer);
                //Console.SetIn(reader);
                app.Run();
            }

        }
    }
}
