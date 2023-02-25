#include <iostream>
using namespace std;
int validateInteger(int number);
main()
{
    int number;
    cout << "Enter a Number: ";
    cin >> number;
    number = validateInteger(number);
}
int validateInteger(int number)
{
    while(number <= 0)
    {
        cout << "Error ! Insert a number greater than zero" << endl;
        cout << "Enter the number again: ";
        cin >> number;
    }
    return number;
}