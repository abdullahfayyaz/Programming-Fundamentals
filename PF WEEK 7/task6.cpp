#include <iostream>
using namespace std;
int frequencyChecker(int number, int digit);
main()
{
    int number;
    int digit;
    int result;
    cout << "Enter Number: ";
    cin >> number;
    cout << "Enter Digit: ";
    cin >> digit;
    result = frequencyChecker(number, digit);
    cout << "Number of digits: " << result;
}
int frequencyChecker(int number, int digit)
{
    int count = 0;
    int modulus;
    while (number != 0)
    {
        modulus = number % 10;
        number = number / 10;
        if (modulus == digit)
        {
            count = count + 1;
        }
    }
    return count;
}
