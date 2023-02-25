#include <iostream>
using namespace std;
main()
{
    int count = 0;
    int number;
    int size;
    cout << "Enter array size: ";
    cin >> size;
    int miles[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number of Miles: ";
        cin >> miles[index];
    }
    for (int index = 0; index < size; index++)
    {
        if (miles[index] < miles[index+1])
        {
            count++;
        }
    }
    count--;
    cout << count;
}