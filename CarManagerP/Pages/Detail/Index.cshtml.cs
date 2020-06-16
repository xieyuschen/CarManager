using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Data;
using CarManagerP.Models;
using CarManagerP.Services;

namespace CarManagerP.Pages.Detail
{
    public class IndexModel : PageModel
    {
        [BindProperty(SupportsGet = true)]
        public string SearchString { get; set; }
        [BindProperty]
        public List<CarDetail> CarDetails { get; set; }
        [BindProperty]
        public string SearchOption { get; set; }
        public IndexModel()
        {
            const string path = @"..\车辆基本信息表.csv";
            CarDetails = new List<CarDetail>();
            var lists = FileService.ReadFromFile(path);

        }

        public async Task OnGetAsync()
        {
            if (!string.IsNullOrEmpty(SearchString))
                CarDetails = CarDetails.Where(t => t.Name.Contains(SearchString)).ToList();
        }
        public async Task OnAsync()
        {
            if (!string.IsNullOrEmpty(SearchString))
                CarDetails = CarDetails.Where(t => t.Name.Contains(SearchString)).ToList();
        }
    }
}
