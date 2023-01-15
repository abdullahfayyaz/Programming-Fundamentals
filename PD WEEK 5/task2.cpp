#include <iostream>
using namespace std;
long long Volume(long long length, long long width, long long height, string unit);
main()
{
    long long length;
    long long width;
    long long height;
    long long volume;
    string unit;
    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Width: ";
    cin >> width;
    cout << "Enter Height: ";
    cin >> height;
    cout << "Enter Unit: ";
    cin >> unit;
    volume = Volume(length, width, height, unit);
    if (unit == "centimeters")
    {
        cout << volume << " cubic centimeters";
    }
    if (unit == "kilometers")
    {
        cout << volume << " cubic kilometers";
    }
    if (unit == "millimeters")
    {
        cout << volume << " cubic millimeters";
    }
}
long long Volume(long long length, long long width, long long height, string unit)
{
    long long volume;
    volume = (length * width * height) / 3.0;
    if (unit == "centimeters")
    {
        volume = volume * (100 * 100 * 100);
        return volume;
    }
    if (unit == "kilometers")
    {
        volume = volume * (1000 * 1000 * 1000);
        return volume;
    }
    if (unit == "millimeters")
    {
        volume = volume * (10 * 10 * 10);
        return volume;
    }
}