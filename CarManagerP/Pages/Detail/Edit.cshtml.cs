using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Data;
using CarManagerP.Models;

namespace CarManagerP.Pages.Detail
{
    public class EditModel : PageModel
    {
        private readonly CarManagerP.Data.CarDetailsContext _context;

        public EditModel(CarManagerP.Data.CarDetailsContext context)
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

        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Attach(CarDetail).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!CarDetailExists(CarDetail.ID))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool CarDetailExists(string id)
        {
            return _context.CarDetail.Any(e => e.ID == id);
        }
    }
}
