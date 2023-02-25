#include <iostream>
using namespace std;
void amplify(int number);
main()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    amplify(number);
}
void amplify(int number)
{
    for (int i = 1; i <= number; i++)
    {
        if (i % 4 == 0)
        {
            i = i * 10;
            cout << i << ",";
            i = i / 10;
            continue;
        }
        cout << i << ",";
    }
}
