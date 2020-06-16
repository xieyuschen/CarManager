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
    public class DeleteModel : PageModel
    {
        public List<CarDetail> Details { get; set; }

        public DeleteModel()
        {
            const string path = @"..\车辆基本信息表.csv";
            Details = new List<CarDetail>();
            var lists = FileService.ReadFromFile(path);
            lists.RemoveAt(0);
            foreach (var item in lists)
            {
                var strs = item.Split("\t");
                Details.Add(new CarDetail
                {
                    CarNum = int.Parse(strs[0]),
                    CarPlateId = strs[1],
                    CarType = strs[2],
                    Name = strs[3],
                    GearType = strs[4],
                    Price = float.Parse(strs[5]),
                    State = strs[6]
                });
            }

        }

        [BindProperty]
        public CarDetail CarDetail { get; set; }

        public async Task<IActionResult> OnGetAsync(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            CarDetail = Details.Find(t => t.CarNum == int.Parse(id));

            if (CarDetail == null)
            {
                return NotFound();
            }
            return Page();
        }

        public async Task<IActionResult> OnPostAsync(string id)
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            var t = Details.Find(t => t.CarNum == CarDetail.CarNum);
            Details.Remove(t);
            const string path = @"..\车辆基本信息表.csv";

            FileService.RewriteFile<CarDetail>(path, Details);
            return RedirectToPage("./Index");

        }
    }
}
