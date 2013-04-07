using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2012QR_SpeakingInTongues_cs
{
    class App
    {
        public void Run()
        {
            string input = Console.ReadLine();
            int T = Convert.ToInt32(input);

            for (int t = 0; t < T; t++)
            {
                var S = Console.ReadLine();

                string G = S;
                var output = "Case #{0}:" + G;
                Console.WriteLine(output, t+1);
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
