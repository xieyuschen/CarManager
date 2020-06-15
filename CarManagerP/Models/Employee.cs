using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace BookStore.Models
{
    public class Employee
    {
        public string Id { get; set; }
        public string Name { get; set; }
        public string Password { get; set; }
        public bool IsManager { get; set; }
    }
}
