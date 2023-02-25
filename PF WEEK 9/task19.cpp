#include <iostream>
using namespace std;
main()
{
    int size;
    int smallest = 0;
    cout << "Enter the size: ";
    cin >> size;
    int num[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter number: ";
        cin >> num[index];
    }
    smallest = num[0];
    for (int i = 0; i < size; i++)
    {
        if (num[i] < smallest)
        {
            smallest = num[i];
        }
    }
    cout << smallest;
}