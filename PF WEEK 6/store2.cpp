#include <iostream>
using namespace std;
float discount(string day, string month, float amount);
main()
{
    string day;
    string month;
    float amount;
    float payable;
    cout << "Enter Day: ";
    cin >> day;
    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter Total Amount: ";
    cin >> amount;
    payable = discount(day, month, amount);
    cout << "Payable amount: " << payable;
}
float discount(string day, string month, float amount)
{
    float payable;
    if (day == "sunday" && month == "october")
    {
        payable = amount - (amount * 10 / 100);
    }
    else
    {
        payable = amount;
    }
    return payable;
}