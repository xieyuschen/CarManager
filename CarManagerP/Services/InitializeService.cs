using CarManagerP.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Services
{
    public class InitializeService
    {
        public static List<BookIngInfo> InitializeBookingInfo(List<string> s)
        {
            List<BookIngInfo> infos = new List<BookIngInfo>();
            foreach (var item in s)
            {
                var strs = item.Split("\t");
                try
                {
                    float.Parse(strs[7]);
                }
                catch
                {
                    continue;

                }
                infos.Add(new BookIngInfo
                {
                    //订单编号    身份证号    客人姓名    手机号码    租用车辆编号  取车时间    预约还车时间
                    //押金（元）	实际还车时间  应缴费用（元）	实缴费用（元）


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
                    ActualPrice = float.Parse(strs[10]),
                    
                });
            }
            return infos;
        }

        public static List<CarDetail> InitializeCarDetail(List<string> s)
        {
            List<CarDetail> details = new List<CarDetail>();
            foreach (var item in s)
            {
                var strs = item.Split("\t");

                try
                {
                    int.Parse(strs[0]);
                }
                catch
                {
                    continue;
                }
                details.Add(new CarDetail
                {
                    CarNum = int.Parse(strs[0]),
                    CarPlateId = strs[1],
                    CarType = strs[2],
                    Name = strs[3],
                    GearType = strs[4],
                    Price = float.Parse(strs[5]),
                    State = strs[6]
                });
            }
            return details;
        }
    }
}
