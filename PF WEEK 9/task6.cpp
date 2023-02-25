#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int number[size];
    int sum = 0;
    int average;
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];
    }
    for (int index = 0; index < size; index++)
    {
        sum = sum + number[index];
    }
    cout << "Sum: " << sum << endl;
    cout << "Average: " << sum / size;
}