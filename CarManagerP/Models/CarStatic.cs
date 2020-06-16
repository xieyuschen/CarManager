using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Models
{
    public class CarStatic
    {
        public string Type { get; set; }
        public  int Total { get; set; }
        public int rent { get; set; }
        public int free { get; set; }
        public override string ToString()
        {
            string t = "\t";
            return Type + t + Total + t + rent + t + free;
        }
    }
}
