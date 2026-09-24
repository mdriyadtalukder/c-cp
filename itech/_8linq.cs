using System;
using System.Linq;
using System.Collections.Generic;

class Employee
{
    public int Id { get; set; }
    public string Name { get; set; }
    public string Department { get; set; }
    public int Salary { get; set; }
}

class Program
{
    static void Main()
    {
        var employees = new List<Employee>
        {
            new Employee { Id = 1, Name = "Riyad", Department = "IT", Salary = 50000 },
            new Employee { Id = 2, Name = "Rahim", Department = "HR", Salary = 60000 },
            new Employee { Id = 3, Name = "Karim", Department = "IT", Salary = 70000 },
            new Employee { Id = 4, Name = "Hasan", Department = "Sales", Salary = 40000 }
        };

        // Where() → filters elements based on a condition
        var where = employees.Where(e => e.Salary > 50000);

        // Select() → selects/transforms specific data
        var select = employees.Select(e => e.Name);

        // OrderBy() → sorts data in ascending order
        var orderBy = employees.OrderBy(e => e.Salary); //OrderByDescending

        // GroupBy() → groups elements having the same key
        var groupBy = employees.GroupBy(e => e.Department);

        // Any() → checks if at least one element exists/matches
        bool any = employees.Any(e => e.Salary > 60000);

        // FirstOrDefault() → returns the first matching element, or null/default
        var firstOrDefault = employees.FirstOrDefault(e => e.Id == 2);

        // Count() → counts elements
        int count = employees.Count();

        // Sum() → calculates total
        int sum = employees.Sum(e => e.Salary);

        // Take() → takes the first N elements
        var take = employees.Take(2);

        // Distinct() → removes duplicate values
        var distinct = employees.Select(e => e.Department).Distinct();

        // Min() → finds minimum value
        int min = employees.Min(e => e.Salary);

        // Average() → calculates average value
        double average = employees.Average(e => e.Salary);

        // Max() → finds maximum value
        int max = employees.Max(e => e.Salary);

        // Reverse() → reverses the order of elements
        var reverse = employees.AsEnumerable().Reverse();

        // Last() → returns the last element
        var last = employees.Last();

        // ToDictionary() → converts data into a Dictionary
        var dictionary = employees.ToDictionary(e => e.Id, e => e.Name);

        // ToList() → converts the result into a List
        var list = employees.Where(e => e.Salary > 50000).ToList();

        // ToArray() → converts the result into an Array
        var array = employees.Select(e => e.Name).ToArray();

        // All() → checks if ALL elements satisfy the condition
        bool all = employees.All(e => e.Salary > 30000);

        // Single() → returns exactly one matching element
        var single = employees.Single(e => e.Id == 1);



        //Reverse a String:
        string s = "hello";
        string rev = new string(s.Reverse().ToArray());

        //Remove Duplicates:
        int[] arr = { 1, 2, 2, 3 };
        var unique = arr.Distinct().ToArray();

        //Count Vowels:
        int count = "hello".Count(c => "aeiou".Contains(c));

        //Longest Word:
        string[] words = sentence.Split();
        string longest = words.OrderByDescending(w => w.Length).First();





    }
}