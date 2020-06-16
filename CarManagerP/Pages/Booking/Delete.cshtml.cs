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

        public DeleteModel(CarManagerP.Data.CarManagerPContext context)
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
