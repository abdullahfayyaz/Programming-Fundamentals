#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int number[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];
    }
    for (int index = size - 1; index >= 0; index--)
    {
        cout << number[index] << endl;
    }
}