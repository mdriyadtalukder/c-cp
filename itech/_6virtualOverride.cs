using System;

class Animal
{
    public virtual void Sound()
    {
        Console.WriteLine("Animal makes sound");
    }
}

class Dog : Animal
{
    public override void Sound()
    {
        Console.WriteLine("Dog barks");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Dog dog = new Dog();

        dog.Sound();
    }
}