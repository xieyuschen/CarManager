using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Permissions;
using System.Text.Json;
using System.Threading.Tasks;
using CarManagerP.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;

namespace CarManagerP.Pages.CarDetails
{
    public class BookInfoModel : PageModel
    {
        [BindProperty(SupportsGet = true)]
        public string SearchString { get; set; }
        [BindProperty]
        public List<CarDetail> CarDetails { get; set; }
        public BookInfoModel()
        {
            const string path = @"..\车辆基本信息表.csv";
            CarDetails = new List<CarDetail>();
            FileStream fStream = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            StreamReader reader = new StreamReader(fStream);
            reader.ReadLine();
            while (!reader.EndOfStream)
            {
                var str = reader.ReadLine();
                var strs=str.Split("\t");
                CarDetails.Add(new CarDetail
                {
                    CarNum=int.Parse(strs[0]),
                    CarPlateId=strs[1],
                    CarType=strs[2],
                    Name= strs[3],
                    GearType = strs[4],
                    Price=float.Parse(strs[5]),
                    State = strs[6]
                });
            }
        }
        public void OnGet()
        {
            if(!string.IsNullOrEmpty(SearchString))
                CarDetails = CarDetails.Where(t => t.Name.Contains(SearchString)).ToList();
        }
    }
}