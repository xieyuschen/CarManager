using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using CarManagerP.Models;
using System.IO;
using System.Text.Json;

namespace CarManagerP.Pages.CarDetails
{
    public class CreateModel : PageModel
    {
        [BindProperty]
        public CarDetail Details { get; set; }
        public void OnGet()
        {

        }
        public async Task<IActionResult> OnPostAsync()
        {
            //写入时要先把所有的读出来，再一行行的读进去避免把原有的数据给覆盖掉
            FileStream fStream = new FileStream("", FileMode.OpenOrCreate);
            StreamReader reader = new StreamReader(fStream);
            string contents = reader.ReadToEnd();
            reader.Close();
            const string path = @"..\车辆基本信息表.csv";

            FileStream fhelp = new FileStream(path, FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fhelp);
            var str = Details.ToString();
            writer.Write(contents);
            await writer.WriteLineAsync(str);
            writer.Close();
            fStream.Close();
            return RedirectToPage("./Cars");
        }
    }
}