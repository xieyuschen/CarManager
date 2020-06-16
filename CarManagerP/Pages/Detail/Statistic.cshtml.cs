using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using CarManagerP.Models;
using CarManagerP.Services;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace CarManagerP.Pages.Detail
{
    public class StatisticModel : PageModel
    {
        [BindProperty]
        public List<CarDetail> CarDetails { get; set; }

        public void OnGet()
        {
            const string path = @"..\车辆基本信息表.csv";
            CarDetails = new List<CarDetail>();
            var lists = FileService.ReadFromFile(path);
            CarDetails = InitializeService.InitializeCarDetail(lists);

        }
    }
}