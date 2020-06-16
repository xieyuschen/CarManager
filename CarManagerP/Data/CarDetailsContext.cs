using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Models;

namespace CarManagerP.Data
{
    public class CarDetailsContext : DbContext
    {
        public CarDetailsContext (DbContextOptions<CarDetailsContext> options)
            : base(options)
        {
        }

        public DbSet<CarManagerP.Models.CarDetail> CarDetail { get; set; }
    }
}
