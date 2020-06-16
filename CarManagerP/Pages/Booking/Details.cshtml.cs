using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Data;
using CarManagerP.Models;

namespace CarManagerP.Pages.Booking
{
    public class DetailsModel : PageModel
    {
        private readonly CarManagerP.Data.CarManagerPContext _context;

        public DetailsModel(CarManagerP.Data.CarManagerPContext context)
        {
            _context = context;
        }

        public BookIngInfo BookIngInfo { get; set; }

        public async Task<IActionResult> OnGetAsync(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            BookIngInfo = await _context.BookIngInfo.FirstOrDefaultAsync(m => m.Id == id);

            if (BookIngInfo == null)
            {
                return NotFound();
            }
            return Page();
        }
    }
}
