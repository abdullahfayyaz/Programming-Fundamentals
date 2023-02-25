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
    cout << "The 2nd element in array is: " << array[1] << endl;
    cout << "The 4th element in array is: " << array[3] << endl;
}