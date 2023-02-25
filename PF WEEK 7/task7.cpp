#include <iostream>
using namespace std;
int digitSum(int number);
main()
{
    int number;
    int result;
    cout << "Enter Number: ";
    cin >> number;
    result = digitSum(number);
    cout << "Sum of digits: " << result;
}
int digitSum(int number)
{
    int sum = 0;
    int mod;
    while (number != 0)
    {
        mod = number % 10;
        number = number / 10;
        sum = sum + mod;
    }
    return sum;
}
