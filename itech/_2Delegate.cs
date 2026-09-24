using System;

public delegate void Greet(string name);

class Program
{
    static void Main(string[] args)
    {
        Greet greet = name => Console.WriteLine("Hello " + name);

        greet("John");
    }
}