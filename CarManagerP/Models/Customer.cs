using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace BookStore.Models
{
    public class Customer
    {
        public string Name { get; set; }
        public string BookName { get; set; }
        public int Count { get; set; }
        public string BookedId { get; set; }
        public DateTime BuyTime { get; set; }
        public double TotalPrice { get; set; }
    }
}
