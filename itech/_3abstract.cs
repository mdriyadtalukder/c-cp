using System;

abstract class Animal
{
    // State
    protected string name;

    // Constructor
    public Animal(string name)
    {
        this.name = name;
    }

    // Normal method - already has logic
    public void Eat()
    {
        Console.WriteLine(name + " is eating");
    }

    // Abstract method - child MUST implement
    public abstract void Sound();
}


// Child class
class Dog : Animal
{
    public Dog(string name) : base(name)
    {
    }

    // Must implement abstract method
    public override void Sound()
    {
        Console.WriteLine(name + " says: Bark");
    }
}