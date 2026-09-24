using System;

interface IAnimal
{
    // Rule: class MUST implement these
    void Sound();
    void Eat();
}


// Class implementing interface
class Dog : IAnimal
{
    public void Sound()
    {
        Console.WriteLine("Dog says: Bark");
    }

    public void Eat()
    {
        Console.WriteLine("Dog is eating");
    }
}