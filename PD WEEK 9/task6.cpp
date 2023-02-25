#include <iostream>
using namespace std;
main()
{
    int transformSize;
    int arraySize;
    cout << "Enter number of times even-odd transformation need to be done: ";
    cin >> transformSize;
    cout << "Enter Array Size: ";
    cin >> arraySize;
    int number[arraySize];
    for (int index = 0; index < arraySize; index++)
    {
        cout << "Enter the array: ";
        cin >> number[index];
    }
    for (int index = 0; index < arraySize; index++)
    {
        for (int idx = 0; idx < transformSize; idx++)
        {
            if (number[index] % 2 == 0)
            {
                number[index] = number[index] - 2;
            }
            else if (number[index] % 2 != 0)
            {
                number[index] = number[index] + 2;
            }
        }
    }
    for (int index = 0; index < arraySize; index++)
    {
        cout << number[index] << ",";
    }
}