#include <iostream>
using namespace std;
main()
{
    bool present = false;
    int mod;
    int num;
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int numbers[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Number: ";
        cin >> numbers[index];
        mod = numbers[index] % 10;
        num = numbers[index] / 10;
        if (numbers[index] == 7)
        {
            present = true;
        }
        else if (mod == 7 || num == 7)
        {
            present = true;
        }
    }
    if (present == true)
    {
        cout << "Boom!";
    }
    else
    {
        cout << "There is no 7 in the array";
    }
}
