#include <iostream>
using namespace std;
main()
{
    int shift = 0;
    int size;
    int colorTime;
    int idx;
    string compare;
    cout << "Enter Number of Colors: ";
    cin >> size;
    colorTime = size * 2;
    string color[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Color: ";
        cin >> color[index];
    }
    for (int index = 0; index < size; index++)
    {
        idx = index + 1;
        if (color[index] == color[idx])
        {
            continue;
        }
        else if (color[index] != color[idx])
        {
            shift++;
        }
    }
    shift--;
    colorTime = size * 2 + shift;
    cout << "Time: " << colorTime << " seconds";
}