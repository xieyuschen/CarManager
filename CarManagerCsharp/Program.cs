using System;
using System.Runtime.InteropServices;
namespace CarManagerCsharp
{
    class Program
    {

        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll", EntryPoint = "Test", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Test();
        static void Main(string[] args)
        {
            Test();
        }
    }
}
