using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Data;
using CarManagerP.Models;

namespace CarManagerP.Pages.Detail
{
    public class IndexModel : PageModel
    {
        private readonly CarManagerP.Data.CarDetailsContext _context;

        public IndexModel(CarManagerP.Data.CarDetailsContext context)
        {
            _context = context;
        }

        public IList<CarDetail> CarDetail { get;set; }

        public async Task OnGetAsync()
        {
            CarDetail = await _context.CarDetail.ToListAsync();
        }
    }
}
