#include <iostream>
using namespace std;
main()
{
 int daysInYear = 365;
 int holidays;
 int workingDays;
 int playTime;
 int difference;
 int hours;
 int minutes;
 cout << "Enter Number of Holidays: ";
 cin >> holidays;
 workingDays = daysInYear - holidays;
 playTime = (workingDays * 63) + (holidays * 127);
 difference = 30000 - playTime;
 if(difference >= 0)
  {
   cout << "Tom sleeps well" << endl;
   hours = difference / 60;
   minutes = difference - (hours * 60);
   cout << hours << " hours " << minutes << " minutes less for play " << endl;
  }
 if(difference < 0)
  {
   cout << "Tom will run away" << endl;
   difference = difference * -1;
   hours = difference / 60;
   minutes = difference - (hours * 60);
   cout << hours << " hours " << minutes << " minutes for play " << endl;
  }
}
  