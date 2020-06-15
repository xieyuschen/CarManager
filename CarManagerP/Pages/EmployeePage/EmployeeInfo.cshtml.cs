using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;
using BookStore.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BookStore.Pages.EmloyeePage
{
    public class EmployeeModel : PageModel
    {
        public List<Employee> Employees { get; set; }
        public EmployeeModel()
        {
            Employees = new List<Employee>();
            FileStream fStream = new FileStream("wwwroot/Employees.txt", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            while (!reader.EndOfStream)
            {
                var str = reader.ReadLine();
                Employees.Add(JsonSerializer.Deserialize<Employee>(str));

            }
        }
            public void OnGet()
        {

        }
    }
}