using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "f";
            string k;
            
            for(;;){
                k = Console.ReadKey().Key.ToString();
                Console.Write("\n" + k +"\n");
                if (string.ReferenceEquals(k,a)) { Console.WriteLine("break");}
            }
            Console.ReadKey();
        }
    }
}
