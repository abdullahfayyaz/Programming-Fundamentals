#include <iostream>
using namespace std;
main()
{
    bool peak = false;
    int range;
    cout << "How many Elements you want to Enter: ";
    cin >> range;
    int element[range];
    for (int index = 0; index < range; index++)
    {
        cout << "Enter Element: ";
        cin >> element[index];
    }
    for (int index = 0; index < range; index++)
    {
        if (element[index] > element[index-1] && element[index] > element[index + 1])
        {
            cout << element[index] << " ";
            peak = true;
        }
    }
    if (peak == false)
    {
        cout << "No Peak Found";
    }
}