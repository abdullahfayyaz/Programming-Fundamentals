#include <iostream>
using namespace std;
void printTable(int number);
main()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    printTable(number);
}

void printTable(int number)
{
    for (int x = 1; x <= 10; x++)
    {
        cout << number << " * " << x << " = " << number * x << endl;
    }
}
