#include <iostream>
using namespace std;
void printCounting(int number);
main()
{
    int number;
    cout << "Enter Number: ";
    cin >> number;
    printCounting(number);
}
void printCounting(int number)
{
    int counting = 1;
    while (counting <= number)
    {
        cout << "\t" << counting << endl;
        counting = counting + 1;
    }
}
