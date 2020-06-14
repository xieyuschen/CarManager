using System;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
namespace CarManagerCsharp
{
    class Program
    {

        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll",CallingConvention = CallingConvention.Cdecl)]
        public static extern void CreateTestClassInstance();
        [DllImport(@"E:\Code\CarManager\Debug\CarManagerDll.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void CallString(byte[] buf);
        static void Main(string[] args)
        {
            byte[] p = new byte[300];
            CallString(p);
            var str = System.Text.Encoding.UTF8.GetString(p);
            Console.WriteLine(str);
        }
    }
}
