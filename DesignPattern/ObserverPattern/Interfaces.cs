interface Subject
{
    void RegisterObserver(Observer o);
    void RemoveObserver(Observer o);
    void NotifyObserver();
}

interface Observer
{
    void Update(float temp, float humidity, float pressure);
}

interface DisplayElement
{
    void Display();
}
