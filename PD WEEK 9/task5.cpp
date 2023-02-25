#include <iostream>
using namespace std;
main()
{
    int count = 0;
    string element[4];
    for (int index = 0; index < 4; index++)
    {
        cout << "Enter Element: ";
        cin >> element[index];
    }
    for (int index = 1; index < 4; index++)
    {
        if (element[0] == element[index])
        {
            count++;
        }
    }
    if (count == 3)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}