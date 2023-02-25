#include <iostream>
using namespace std;
main()
{
    int size;
    float sum = 0;
    cout << "Enter Array Size: ";
    cin >> size;
    float resistance[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Resistance: ";
        cin >> resistance[index];
    }
    for (int index = 0; index < size; index++)
    {
        sum = sum + resistance[index];
    }
    cout << "Total resistance of the circuit: " << sum << " ohms ";
}
