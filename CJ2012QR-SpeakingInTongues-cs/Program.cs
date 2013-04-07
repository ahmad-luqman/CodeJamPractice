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
            
            var charDictionary = new Dictionary<char, char>();
            string []mapInput = new string[3];
            string []mapOutput = new string[3];
            mapInput[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
            mapInput[1] ="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
            mapInput[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
            mapOutput[0] = "our language is impossible to understand";
            mapOutput[1] ="there are twenty six factorial possibilities";
            mapOutput[2] = "so it is okay if you want to just give up";
            for (int i = 0; i < mapInput.Length; i++)
            {
                for (int j = 0; j < mapInput[i].Length; j++)
                {
                    char c = mapInput[i][j];
                    if (!charDictionary.ContainsKey(c))
                    {
                        charDictionary[c] = mapOutput[i][j];
                    }
                }
            }
            charDictionary['z'] = 'q';
            charDictionary['q'] = 'z';

            for (int t = 0; t < T; t++)
            {
                var S = Console.ReadLine();

                string G = string.Empty;
                foreach (var c in S)
                {
                    if (charDictionary.ContainsKey(c))
                        G += charDictionary[c];
                    else
                        G += "#";
                }

                var output = "Case #{0}: " + G;
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
