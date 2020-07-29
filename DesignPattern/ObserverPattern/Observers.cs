using System;

class CurrentConditionsDisplay : Observer, DisplayElement
{
    public float Temperature { get; set; }
    public float Humidity { get; set; }
    public Subject WeatherData { get; set; }

    public CurrentConditionsDisplay(Subject weatherData)
    {
        WeatherData = weatherData;
        weatherData.RegisterObserver(this);
    }

    public void Update(float t, float h, float p)
    {
        Temperature = t;
        Humidity = h;
        Display();
    }

    public void Display()
    {
        Console.WriteLine($"Current conditions : {Temperature} F degrees and {Humidity}% humidity");
    }
}