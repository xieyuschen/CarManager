using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Permissions;
using System.Text.Json;
using System.Threading.Tasks;
using BookStore.Models;
using CarManagerP.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace BookStore.Pages.Logic
{
    public class BookInfoModel : PageModel
    {
        [BindProperty(SupportsGet = true)]
        public string SearchString { get; set; }

        public List<CarDetail> CarDetails { get; set; }
        public BookInfoModel()
        {
            const string path = "";
            CarDetails = new List<CarDetail>();
            FileStream fStream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            while (!reader.EndOfStream)
            {
                var str = reader.ReadLine();
                var strs=str.Split("\t");
                CarDetails.Add(new CarDetail
                {
                    
                });
            }
        }
        public void OnGet()
        {
            if(!string.IsNullOrEmpty(SearchString))
                CarDetails = CarDetails.Where(t => t.Publisher.Contains(SearchString)).ToList();
        }
    }
}