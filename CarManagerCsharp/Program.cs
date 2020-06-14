using System;
using System.Runtime.InteropServices;
namespace CarManagerCsharp
{
    class Program
    {

        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll",CallingConvention = CallingConvention.Cdecl)]
        public static extern void CreateTestClassInstance();
        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void CallClassTester();
        static void Main(string[] args)
        {
            CreateTestClassInstance();
            CallClassTester();
        }
    }
}
