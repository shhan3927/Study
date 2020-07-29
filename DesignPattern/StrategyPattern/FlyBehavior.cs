using System;

interface FlyBehavior
{
    void Fly();
}

class FlyWithWings : FlyBehavior
{
    public void Fly()
    {
        Console.WriteLine("날다");
    }
}

class FlyNoWay : FlyBehavior
{
    public void Fly()
    {
        Console.WriteLine("날지 않다.");
    }
}