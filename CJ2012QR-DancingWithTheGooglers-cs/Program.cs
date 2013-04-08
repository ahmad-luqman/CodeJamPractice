using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2012QR_DancingWithTheGooglers_cs
{
    class App
    {
        public void Run()
        {
            string input = Console.ReadLine();
            int T = Convert.ToInt32(input);

            for (int t = 0; t < T; t++)
            {
                var str = Console.ReadLine();

                string[] sArray = str.Split(null);
                int N = Convert.ToInt32(sArray[0]);
                int S = Convert.ToInt32(sArray[1]);
                int p = Convert.ToInt32(sArray[2]);

                int []ti = new int[N];
                int nonSCount = 0;
                int SCount = 0;
                for (int i = 0; i < N; i++)
                {
                    ti[i] = Convert.ToInt32(sArray[i + 3]);
                    int tAtI = ti[i];

                    if ((p * 3 - 2) <= tAtI) nonSCount++;
                    else if (1 > tAtI && tAtI < 29) continue;
                    else if ((p * 3 - 4) <= tAtI) SCount++;
                }

                int y = nonSCount + Math.Min(SCount, S);
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
            using (StreamReader reader = new StreamReader(@"B-large-practice.in"))
            {
                //Console.SetOut(writer);
                Console.SetIn (reader);
                app.Run();
            }
            
        }
    }

}
