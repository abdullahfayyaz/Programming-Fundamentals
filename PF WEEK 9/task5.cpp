#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int number[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];
    }
    for (int index = 0; index < size; index++)
    {
        cout << number[index] << endl;
    }
}