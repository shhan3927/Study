using System;

class Duck
{
    public virtual void Swim() {}
    public virtual void Display() {}

    public FlyBehavior Fly { set; get; }
    public QuackBehavior Quack { set; get; }

    public void PerformFly()
    {
        Fly.Fly();
    }

    public void PerformQuack()
    {
        Quack.Sound();
    }
}

class MallardDuck : Duck
{
    public MallardDuck()
    {   
        Fly = new FlyWithWings();
        Quack = new Quack();
    }

    public override void Display()
    {
        Console.WriteLine("MallardDuck");
    }
}

class RubberDuck : Duck
{
    public RubberDuck()
    {   
        Fly = new FlyNoWay();
        Quack = new Quack();
    }

    public override void Display()
    {
        Console.WriteLine("RubberDuck");
    }
}

class RedheadDuck : Duck
{
    public RedheadDuck()
    {   
        Fly = new FlyWithWings();
        Quack = new Quack();
    }

    public override void Display()
    {
        Console.WriteLine("RedheadDuck");
    }
}

class DecoyDuck : Duck
{
    public DecoyDuck()
    {   
        Fly = new FlyNoWay();
        Quack = new MuteQuack();
    }

    public override void Display()
    {
        Console.WriteLine("DecoyDuck");
    }
}