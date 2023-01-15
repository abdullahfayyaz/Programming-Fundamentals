#include <iostream>
using namespace std;
main()
{
    char serviceCode;
    char time;
    int minutes;
    float charges;
    float extraCharges;
    cout << "Enter which type of customer you are (Regular or Premium) select (r/p): ";
    cin >> serviceCode;
    cout << "(Press 'D' for day time or Press 'N' for night time) call: ";
    cin >> time;
    cout << "Enter number of minutes you used the service: ";
    cin >> minutes;
    if (serviceCode == 'r' || serviceCode == 'R')
    {
        charges = 10.00;
        cout << "The charges are: " << charges << " $";
        if (minutes > 50)
        {
            extraCharges = minutes - 50;
            extraCharges = extraCharges * 0.20 + 10.00;
            cout << "The charges are: " << extraCharges << " $";
        }
    }
    else if (serviceCode == 'p' || serviceCode == 'P')
    {
        charges = 25.00;
        cout << "The charges are: " << charges << " $";
        if (time == 'D' && minutes > 75)
        {
            extraCharges = minutes - 75;
            extraCharges = extraCharges * 0.10 + 25.00;
            cout << "The charges are: " << extraCharges << " $";
        }
        else if (time == 'N' && minutes > 100)
        {
            extraCharges = minutes - 100;
            extraCharges = extraCharges * 0.05 + 25.00;
            cout << "The charges are: " << extraCharges << " $";
        }
    }
}
