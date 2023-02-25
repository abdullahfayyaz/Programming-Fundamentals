#include <iostream>
using namespace std;
main()
{
    int size = 5;
    int array[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter element: ";
        cin >> array[index];
    }
    cout << "The 1st element in array is: " << array[0] << endl;
    cout << "The last element in array is: " << array[4] << endl;
}