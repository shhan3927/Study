using System;

namespace ObserverPattern
{
    class Program
    {
        static void Main(string[] args)
        {
            var weatherData = new WeatherData();
            var currentDisplay = new CurrentConditionsDisplay(weatherData);

            weatherData.SetMeasurements(80, 65, 30.4f);
            weatherData.SetMeasurements(82, 70, 29.2f);
        }
    }
}
