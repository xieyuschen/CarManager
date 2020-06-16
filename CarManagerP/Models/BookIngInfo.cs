using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Models
{
	
    public class BookIngInfo
    {
		//订单编号    身份证号    客人姓名    手机号码    租用车辆编号  取车时间    预约还车时间
		//押金（元）	实际还车时间  应缴费用（元）	实缴费用（元）

		public string Id { get; set; }
		public string IdentityId { get; set; }
		public string CustomerName { get; set; }
		public string CarId { get; set; }
		public string FetchTime { get; set; }
		public string ReturnTime { get; set; }
		public float Deposit { get; set; }
		public string ActualReturnTime { get; set; }
		public float DeservePrice { get; set; }
		public float ActualPrice { get; set; }
		public string Telephone { get; set; }

		public string SearchString { get; set; }

		public override string ToString()
		{
			string t = "\t";
			return Id + t + IdentityId + t + CustomerName + t + Telephone + t + CarId + t + FetchTime + t + ReturnTime + t + Deposit + t
				+ ActualReturnTime+t + DeservePrice+t + ActualReturnTime + t + DeservePrice + t + ActualReturnTime;
		}
	}
}
