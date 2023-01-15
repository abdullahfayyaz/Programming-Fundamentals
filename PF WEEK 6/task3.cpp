#include <iostream>
using namespace std;
bool sameNumber(int number1, int number2, int number3);
main()
{
    int number1;
    int number2;
    int number3;
    cout << "Enter 1st Number: ";
    cin >> number1;
    cout << "Enter 2nd Number: ";
    cin >> number2;
    cout << "Enter 3rd Number: ";
    cin >> number3;
    sameNumber(number1, number2, number3);
}
bool sameNumber(int number1, int number2, int number3)
{
    if (number1 == number2 && number1 == number3)
    {
        cout << "yes";
        return true;
    }
    else
    {
        cout << "no";
        return false;
    }
}