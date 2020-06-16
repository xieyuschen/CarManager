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
    public class DeleteModel : PageModel
    {
        private readonly CarManagerP.Data.CarDetailsContext _context;

        public DeleteModel(CarManagerP.Data.CarDetailsContext context)
        {
            _context = context;
        }

        [BindProperty]
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

        public async Task<IActionResult> OnPostAsync(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            CarDetail = await _context.CarDetail.FindAsync(id);

            if (CarDetail != null)
            {
                _context.CarDetail.Remove(CarDetail);
                await _context.SaveChangesAsync();
            }

            return RedirectToPage("./Index");
        }
    }
}
