#include <iostream>
using namespace std;
main()
{
    int size;
    int array[2];
    cout << "Enter 2nd Array Size: ";
    cin >> size;
    int array2[size];
    for (int index = 0; index < 2; index++)
    {
        cout << "Enter 1st Array Element: ";
        cin >> array[index];
    }
    for (int index = 0; index < size; index++)
    {
        cout << "Enter 2nd Array Element: ";
        cin >> array2[index];
    }
    cout << array[0] << ",";
    for (int index = 0; index < size; index++)
    {
        cout << array2[index] << ",";
    }
    cout << array[1];
}
