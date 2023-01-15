#include<iostream>
using namespace std;
main()
{
    int hours;
    int minutes;
    int newHours;
    int newMinutes;
    cout << "Enter Hours (0 - 23): ";
    cin >> hours;
    cout << "Enter Minutes (0 - 59): ";
    cin >> minutes;
    newMinutes = minutes + 15;
    if(newMinutes <= 60)
    {
        cout << hours << ":" << newMinutes;
    }
    if(newMinutes > 60)
    {
        newHours = hours + 1;
        newMinutes = newMinutes - 60;
        cout << newHours << ":" << newMinutes;
    }

}