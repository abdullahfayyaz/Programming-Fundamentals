#include <iostream>
using namespace std;
main()
{
    int examHour;
    int exmaMinutes;
    int arrivalHour;
    int arrivalMinutes;
    int totalExamTime;
    int totalArrivalTime;
    int time, hour, minutes;
    cout << "Enter Exam Starting Time(hours): ";
    cin >> examHour;
    cout << "Enter Exam Starting Time(minutes): ";
    cin >> exmaMinutes;
    cout << "Enter Hour of Arrival: ";
    cin >> arrivalHour;
    cout << "Enter Minutes of Arrival: ";
    cin >> arrivalMinutes;
    totalExamTime = examHour * 60 + exmaMinutes;
    totalArrivalTime = arrivalHour * 60 + arrivalMinutes;
    if (totalArrivalTime > totalExamTime)
    {
        cout << "Late" << endl;
        time = totalArrivalTime - totalExamTime;
        if (time <= 59)
        {
            cout << time << " minutes after the start";
        }
        else if (time > 60)
        {
            hour = arrivalHour - examHour;
            minutes = arrivalMinutes - exmaMinutes;
            cout << hour << ":" << minutes << " hours after the start";
        }
    }
    else if ((totalArrivalTime == totalExamTime) || ((totalExamTime - totalArrivalTime) <= 30))
    {
        cout << "On Time" << endl;
        time = totalExamTime - totalArrivalTime;
        if (time > 0 && time <= 30)
        {
            cout << time << " minutes before the start";
        }
    }
    else if (totalArrivalTime < totalExamTime)
    {
        cout << "Early" << endl;
        time = totalExamTime - totalArrivalTime;
        if (time <= 59)
        {
            cout << time << " minutes before the start";
        }
        else if (time > 59)
        {
            hour = examHour - arrivalHour;
            minutes = exmaMinutes - arrivalMinutes;
            cout << hour << ":" << minutes << " hours before the start";
        }
    }
}