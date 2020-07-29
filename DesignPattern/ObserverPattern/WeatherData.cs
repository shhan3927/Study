using System.Collections.Generic;

class WeatherData : Subject
{
    public void RegisterObserver(Observer o)
    {
        observers.Add(o);
    }

    public void RemoveObserver(Observer o)
    {
        observers.Remove(o);
    }

    public void NotifyObserver()
    {
        foreach(var o in observers)
        {
            o.Update(Temperature, Humidity, Pressure);
        }
    }

    public void MeasurementsChanged()
    {
        NotifyObserver();
    }

    public void SetMeasurements(float t, float h, float p)
    {
        Temperature = t;
        Humidity = h;
        Pressure = p;
        MeasurementsChanged();
    }

    public float Temperature { get;set; }
    public float Humidity { get;set; }
    public float Pressure { get;set; }

    private List<Observer> observers = new List<Observer>();
}
