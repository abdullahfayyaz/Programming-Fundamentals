#include <iostream>
using namespace std;
int totalDigits(int number);
main()
{
    int number;
    int result;
    cout << "Enter Number: ";
    cin >> number;
    result = totalDigits(number);
    cout << "Number of digits: " << result;
}
int totalDigits(int number)
{
    int count = 0;
    while (number != 0)
    {
        number = number / 10;
        count = count + 1;
    }
    return count;
}
