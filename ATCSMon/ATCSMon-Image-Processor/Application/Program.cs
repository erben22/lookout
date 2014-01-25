
using System;
using System.Reflection;

namespace ATCSMon_Image_Processor
{
    class Program
    {
        static void Main(string[] args)
        {
            if (0 == args.Length)
            {
                Console.WriteLine(AppResources.WelcomeString + Assembly.GetExecutingAssembly().FullName);
            }
        }
    }
}
