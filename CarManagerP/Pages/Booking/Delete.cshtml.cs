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
    public class DeleteModel : PageModel
    {
        public List<BookIngInfo> bookIngInfos { get; set; }

        public DeleteModel()
        {
            const string path = @"..\租车订单信息表.csv";
            var lists = FileService.ReadFromFile(path);
            bookIngInfos = InitializeService.InitializeBookingInfo(lists);
        }

        [BindProperty]
        public BookIngInfo BookIngInfo { get; set; }

        public async Task<IActionResult> OnGetAsync(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            BookIngInfo = bookIngInfos.Find(m => m.Id == id);

            if (BookIngInfo == null)
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
            const string path = @"..\租车订单信息表.csv";
            BookIngInfo = bookIngInfos.Find(m => m.Id == id);
            bookIngInfos.Remove(BookIngInfo);
            FileService.RewriteFile(path, bookIngInfos);
            return RedirectToPage("./Index");
        }
    }
}
