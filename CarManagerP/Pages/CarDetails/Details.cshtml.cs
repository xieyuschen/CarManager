using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using CarManagerP.Models;
using System.Runtime.InteropServices;

namespace CarManagerP.Pages.CarDetails
{

    public class DetailsModel : PageModel
    {
        //https://localhost:44365/CarDetails/details

        [DllImport(@"E:\Code\CarManager\Debug\PureCdll.dll", CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.LPWStr)]
        public static extern string CsvReader([MarshalAs(UnmanagedType.LPStr)] string path, int row);

        [DllImport(@"E:\Code\CarManager\Debug\PureCdll.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.LPWStr)]
        public static extern string Test();
        [BindProperty]
        public CarDetail CarDetail { get; set; }
        public DetailsModel()
        {
            var str = Test(); /*CsvReader("../车辆基本信息表.csv", 1);*/
        }
        public void OnGet()
        {

        }
    }
}