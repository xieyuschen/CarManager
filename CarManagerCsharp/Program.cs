using System;
using System.Runtime.InteropServices;
namespace CarManagerCsharp
{
    class Program
    {

        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll",EntryPoint ="add", CallingConvention = CallingConvention.Cdecl)]
        public static extern int add(int a,int b);
        static void Main(string[] args)
        {
            try
            {
                int a = 1, b = 2;
                int p = add(a, b);
                Console.WriteLine(p);

            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}
