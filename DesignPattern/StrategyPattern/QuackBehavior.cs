using System;

interface QuackBehavior
{
    void Sound();
}

class Quack : QuackBehavior
{
    public void Sound()
    {
        Console.WriteLine("꽥꽥");
    }
}

class Squeak : QuackBehavior
{
    public void Sound()
    {
        Console.WriteLine("삑삑");
    }
}

class MuteQuack : QuackBehavior
{
    public void Sound()
    {
        Console.WriteLine("아무 소리 안남");
    }
}