using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using CarManagerP.Data;
using CarManagerP.Models;
using CarManagerP.Services;

namespace CarManagerP.Pages.Detail
{
    public class CreateModel : PageModel
    {
        private List<CarDetail> Details;
        [BindProperty]
        public CarDetail CarDetail { get; set; }

        public CreateModel()
        {
            const string path = @"..\车辆基本信息表.csv";
            var lists = FileService.ReadFromFile(path);
            Details = InitializeService.InitializeCarDetail(lists);
            
        }

        public IActionResult OnGet()
        {
            return Page();
        }


        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            Details.Add(CarDetail);
            const string path = @"..\车辆基本信息表.csv";
            FileService.RewriteFile(path, Details);
            return RedirectToPage("./Index");
        }
    }
}
