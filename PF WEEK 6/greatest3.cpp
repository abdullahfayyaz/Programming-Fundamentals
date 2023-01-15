#include <iostream>
using namespace std;
main()
{
    int number1;
    int number2;
    cout << "Enter 1st Number: ";
    cin >> number1;
    cout << "Enter 2nd Number: ";
    cin >> number2;
    if (number1 > number2)
    {
        cout << "Greater Number is: " << number1;
    }
    else
    {
        cout << "Greater Number is: " << number2;
    }
}