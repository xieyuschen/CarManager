using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using CarManagerP.Models;

namespace CarManagerP.Data
{
    public class CarManagerPContext : DbContext
    {
        public CarManagerPContext (DbContextOptions<CarManagerPContext> options)
            : base(options)
        {
        }

        public DbSet<CarManagerP.Models.BookIngInfo> BookIngInfo { get; set; }
    }
}
