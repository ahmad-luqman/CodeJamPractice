using System;
using System.Collections.Generic;
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
                for (int i = 0; i < N; i++)
                    ti[i] = Convert.ToInt32(sArray[i + 3]);

                string y = str;
                var output = "Case #{0}:" + y;
                Console.WriteLine(output, t + 1);
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var app = new App();
            app.Run();
        }
    }

}
