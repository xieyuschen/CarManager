using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Models
{
    public class CarDetail
    {
		public int CarNum { get; set; }
		public string CarPlateId { get; set; }
		public string CarType { get; set; }
		public string Name { get; set; }
		public string GearType { get; set; }
		public float Price { get; set; }
		public string State { get; set; }
		public string SearchString { get; set; }

		public override string ToString()
		{
			string t = "\t";
			return CarNum + t + CarPlateId + t + CarType + t + Name + t + GearType + t + Price + t + State;
		}
	}
}
