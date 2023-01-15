#include <iostream>
using namespace std;
string activity(string temperature, string humidity, string result);
main()
{
    string temperature;
    string humidity;
    string result;
    cout << "Enter Temperature: ";
    cin >> temperature;
    cout << "Enter Humidity: ";
    cin >> humidity;
    result = activity(temperature, humidity, result);
    cout << "Activity: " << result;
}
string activity(string temperature, string humidity, string result)
{
    if (temperature == "warm")
    {
        if (humidity == "dry")
        {
            result = "Play Tennis";
        }
        else if (humidity == "humid")
        {
            result = "Swim";
        }
    }
    else if (temperature == "cold")
    {
        if (humidity == "dry")
        {
            result = "Play Basketball";
        }
        else if (humidity == "humid")
        {
            result = "Watch TV";
        }
    }
    return result;
}