public class AppDbContext : DbContext
{
    public DbSet<Employee> Employees { get; set; }
}