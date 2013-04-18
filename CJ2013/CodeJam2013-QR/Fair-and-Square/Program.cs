using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fair_and_Square
{
    class App
    {
        const long MAX = 10000000;
        List<long> fairAndSquare;
        Dictionary<long, long> dict;

        public App()
        {
            fairAndSquare = new List<long>();
            dict = new Dictionary<long, long>();
        }

        bool isPalindrome(long num)
        {
            long n = num;
            long rev = 0;
            while (num > 0)
            {
                long dig = num % 10;
                rev = rev * 10 + dig;
                num = num / 10;
            }
            return n == rev;
        }

        public void preCompute()
        {
            for (long num = 1; num <= MAX; num++)
                if (isPalindrome(num))
                    if (isPalindrome(num * num))
                    {
                        dict[num] = num * num;
                        fairAndSquare.Add(num);
                    }
        }

        public void Run()
        {
            string input = Console.ReadLine();
            int T = Convert.ToInt32(input);

            for (int t = 0; t < T; t++)
            {
                //var str = Console.ReadLine();
                int count = 0;
                string[] p = Console.ReadLine().Split(null);
                long A = long.Parse(p[0]);
                long B = long.Parse(p[1]);

                //for (long i = (int)Math.Sqrt(A); i <= Math.Sqrt(B); i++)
                //{
                //    //fairAndSquare.Find(n => n == i);

                //    //if (fairAndSquare.Any(n => n == i))
                //    if(dict.ContainsKey(i))
                //        count++;
                //}
                long sqrtA = (long)Math.Sqrt(A);
                long sqrtB = (long)Math.Sqrt(B);
                //count = fairAndSquare.Count(n => n >= sqrtA && n <= sqrtB);
                count = dict.Count(n => n.Value >= A && n.Value <= B);


                string y = count.ToString();

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

            using (StreamWriter writer = new StreamWriter("out.txt"))
            using (StreamReader reader = new StreamReader(@"C:\Users\aluqman\Downloads\C-large-practice-2.in"))
            {
                Console.SetOut(writer);
                Console.SetIn(reader);

                app.preCompute();
                app.Run();
            }

        }
    }
}
