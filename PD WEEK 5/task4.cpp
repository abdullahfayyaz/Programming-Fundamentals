#include <iostream>
using namespace std;
main()
{
    int neededHours;
    int days;
    int workers;
    int workingHoursPerDay = 10;
    int totalWorkingHours;
    int moreHoursNeeded;
    int hoursLeft;
    cout << "Enter Needed Hours (0 - 200000): ";
    cin >> neededHours;
    cout << "Enter Number of Days (0 - 20000): ";
    cin >> days;
    cout << "Enter Number of Workers (0 - 200): ";
    cin >> workers;
    workingHoursPerDay = workingHoursPerDay * 10 / 100;
    workingHoursPerDay = workers * (10 - workingHoursPerDay);
    totalWorkingHours = workingHoursPerDay * days;
    if (totalWorkingHours < neededHours)
    {
        moreHoursNeeded = neededHours - totalWorkingHours;
        cout << "Not enough time! " << moreHoursNeeded << " hours needed";
    }
    if (totalWorkingHours > neededHours)
    {
        hoursLeft = totalWorkingHours - neededHours;
        cout << "Yes! " << hoursLeft << " hours left";
    }
    return 0;
}
