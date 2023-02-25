#include <iostream>
using namespace std;
main()
{
    int size;
    int sum = 0;
    cout << "Enter Size: ";
    cin >> size;
    int number[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];
    }
    for (int index = 0; index < size; index = index + 3)
    {
        sum = sum + (number[index] * number[index + 1] * number[index + 2]);
    }
    cout << "Sum: " << sum;
}