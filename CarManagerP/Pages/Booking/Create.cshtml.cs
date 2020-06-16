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

        public CreateModel()
        {
            const string path = @"..\租车订单信息表.csv";
            var lists = FileService.ReadFromFile(path);
            lists.RemoveAt(0);
            foreach (var item in lists)
            {
                var strs = item.Split("\t");
                bookIngInfos.Add(new BookIngInfo
                {
                    //订单编号    身份证号    客人姓名    手机号码    租用车辆编号  取车时间    预约还车时间  押金（元）	实际还车时间  应缴费用（元）	实缴费用（元）                     = int.Parse(strs[0]),
                    Id = strs[0],
                    IdentityId = strs[1],
                    CustomerName = strs[2],
                    Telephone = strs[3],
                    CarId = strs[4],
                    FetchTime = strs[5],
                    ReturnTime = strs[6],
                    Deposit = float.Parse(strs[7]),
                    ActualReturnTime = strs[8],
                    DeservePrice = float.Parse(strs[9]),
                    ActualPrice = float.Parse(strs[10])
                });
            }

        }

        public IActionResult OnGet()
        {
            return Page();
        }


        // To protect from overposting attacks, enable the specific properties you want to bind to, for
        // more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {

            return RedirectToPage("./Index");
        }
    }
}
