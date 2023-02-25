#include <iostream>
using namespace std;
main()
{
    int size;
    int number2;
    cout << "Enter Array Size: ";
    cin >> size;
    int number[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];
    }
    cout << "Enter Another Number: ";
    cin >> number2;
    for (int index = 0; index < size; index++)
    {
        if (number2 == number[index])
        {
            cout << "Already Entered";
            break;
        }
    }
}