using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CJ2012QR_RecycledNumbers_cs
{
    class Program
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

                    var output = "Case #{0}: ";// +y;
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
}
