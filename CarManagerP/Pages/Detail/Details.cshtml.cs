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
    public class DetailsModel : PageModel
    {
        private readonly CarManagerP.Data.CarDetailsContext _context;

        public DetailsModel(CarManagerP.Data.CarDetailsContext context)
        {
            _context = context;
        }

        public CarDetail CarDetail { get; set; }

        public async Task<IActionResult> OnGetAsync(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            CarDetail = await _context.CarDetail.FirstOrDefaultAsync(m => m.ID == id);

            if (CarDetail == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
