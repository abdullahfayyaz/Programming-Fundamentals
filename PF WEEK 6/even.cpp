#include <iostream>
using namespace std;

string isEven(int number);

main()
{
    int number;
    string result;
    cout << "Enter Number: ";
    cin >> number;
    result = isEven(number);
    cout << result;
}
string isEven(int number)
{
    int remainder;
    string result;
    remainder = number % 2;
    if (remainder == 0)
    {
        result = "Even";
    }
    else
    {
        result = "Odd";
    }
    return result;
}
