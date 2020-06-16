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

namespace CarManagerP.Pages.Booking
{
    public class IndexModel : PageModel
    {
        [BindProperty]
        public List<BookIngInfo> BookIngInfos { get; set; }

        [BindProperty]
        public string SearchString { get; set; }
        public IndexModel(CarManagerP.Data.CarManagerPContext context)
        {
            const string path = @"..\租车订单信息表.csv";
            var lists = FileService.ReadFromFile(path);
            BookIngInfos= InitializeService.InitializeBookingInfo(lists);
        }
        public async Task OnGetAsync()
        {
            if (!string.IsNullOrEmpty(SearchString))
                BookIngInfos = BookIngInfos.Where(t => t.CarId.Contains(SearchString)).ToList();
        }
    }
}
