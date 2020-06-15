using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;
using BookStore.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BookStore.Pages.CustomerPage
{
    public class CreateModel : PageModel
    {
        [BindProperty]
        public Customer Customer { get; set; }
        public void OnGet()
        {

        }
        public async Task<IActionResult> OnPostAsync()
        {
            FileStream fStream = new FileStream("wwwroot/Customers.txt", FileMode.OpenOrCreate);
            StreamReader reader = new StreamReader(fStream);
            string contents = reader.ReadToEnd();
            reader.Close();

            FileStream fhelp = new FileStream("wwwroot/Customers.txt", FileMode.OpenOrCreate, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fhelp);
            var str = JsonSerializer.Serialize(Customer);
            writer.Write(contents);
            await writer.WriteLineAsync(str);
            writer.Close();
            fStream.Close();
            return RedirectToPage("./CustomerInfo");
        }
    }
}