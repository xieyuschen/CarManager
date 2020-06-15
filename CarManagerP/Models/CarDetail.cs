using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace CarManagerP.Models
{
    public class CarDetail
    {
		public int CarNum;
		public string CarPlateId;
		public string CarType;
		public string Name;
		public string GearType;
		public float Price;
		public string State;

		public string SearchString;

		public override string ToString()
		{
			string t = "\t";
			return CarNum + t + CarPlateId + t + CarType + t + Name + t + GearType + t + Price + t + State;
		}
	}
}
