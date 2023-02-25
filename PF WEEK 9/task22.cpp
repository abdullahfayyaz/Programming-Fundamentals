#include <iostream>
using namespace std;
main()
{
    int size = 4;
    float amount[size];
    float quarter, dime, nickel, penny;
    float sum, due;
    cout << "Enter total due: ";
    cin >> due;
    for (int index = 0; index < size; index++)
    {
        cout << "Enter amount of change: ";
        cin >> amount[index];
    }
    quarter = amount[0] * 0.25;
    dime = amount[1] * 0.10;
    nickel = amount[2] * 0.05;
    penny = amount[3] * 0.01;
    sum = quarter + dime + nickel + penny;
    if(sum - due >= 0)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}