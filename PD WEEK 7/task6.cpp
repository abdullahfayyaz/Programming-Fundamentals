#include <iostream>
using namespace std;
main()
{
    int days;
    int patients;
    int treated = 0, untreated = 0;
    int doctors = 7;
    cout << "Enter Number of Days: ";
    cin >> days;
    for (int x = 1; x <= days; x = x + 1)
    {
        cout << "Enter number of patients for " << x << " days:";
        cin >> patients;
        if ((x % 3 == 0) && (untreated - treated > 0))
        {
            doctors = doctors + 1;
        }
        if (patients > doctors)
        {
            treated = treated + doctors;
            untreated = untreated + (patients - doctors);
        }
        else
        {
            treated = treated + patients;
        }
    }
    cout << "Treated: " << treated << endl;
    cout << "Untreated: " << untreated << endl;
}