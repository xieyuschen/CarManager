using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Models
{
	
    public class BookIngInfo
    {		
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
	}
}
