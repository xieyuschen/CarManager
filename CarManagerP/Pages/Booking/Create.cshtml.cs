using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using CarManagerP.Data;
using CarManagerP.Models;
using CarManagerP.Services;

namespace CarManagerP.Pages.Booking
{
    public class CreateModel : PageModel
    {
        [BindProperty]
        public BookIngInfo BookIngInfo { get; set; }
        public List<BookIngInfo> bookIngInfos { get; set; }
        const string path = @"..\租车订单信息表.csv";

        public CreateModel()
        {
            var lists = FileService.ReadFromFile(path);
            bookIngInfos = InitializeService.InitializeBookingInfo(lists);

        }

        public IActionResult OnGet()
        {
            return Page();
        }


        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            FileService.AppendFile(path, BookIngInfo);
            return RedirectToPage("./Index");
        }
    }
}
