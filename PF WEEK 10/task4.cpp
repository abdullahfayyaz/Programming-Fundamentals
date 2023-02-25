#include <iostream>
using namespace std;

bool iscycle(int cycleLength, int arrSize);


int number[1];

main()
{
    int arrSize;
    cout << "Enter Array Size: ";
    cin >> arrSize;
    number[1] = number[arrSize];

    for (int x = 0; x < arrSize; x++)
    {
        cout << "Enter Number " << x + 1 << ": ";
        cin >> number[x];
    }

    int cycleLength;
    cout << "Enter Cycle Length: ";
    cin >> cycleLength;
    bool check = iscycle(cycleLength, arrSize);

    if(check == true)
    {
        cout<<"true";
    }
    
    else if(check == false)
    {
        cout<<"false";
    }
}

bool iscycle(int cycleLength, int arrSize)
{
    bool check = true;
    for (int x = 0; x + cycleLength < arrSize; x++)
    {
        if (number[x] != number[x + cycleLength])
        {
            check = false;
        }
    }
    if (check == true)
    {
        return true;
    }
    else if (check == false)
    {
        return false;
    }
}