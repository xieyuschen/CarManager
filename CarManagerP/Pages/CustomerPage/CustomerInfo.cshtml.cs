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
    public class CustomerInfoModel : PageModel
    {
        public List<Customer> Customers { get; set; }
        public void OnGet()
        {

        }
        public CustomerInfoModel()
        {
            Customers = new List<Customer>();
            FileStream fStream = new FileStream("wwwroot/Customers.txt", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            while (!reader.EndOfStream)
            {
                var str = reader.ReadLine();
                Customers.Add(JsonSerializer.Deserialize<Customer>(str));
            }
        }
    }
}