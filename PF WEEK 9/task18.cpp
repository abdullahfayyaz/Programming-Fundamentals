#include <iostream>
using namespace std;
main()
{
    int largest = 0;
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int number[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> number[index];

        if (number[index] > largest)
        {
            largest = number[index];
        }
    }
    cout << "Largest Number: " << largest;
}