#include <iostream>
using namespace std;
float totalIncome(string screen, int rows, int columns);
main()
{
    string screen;
    int rows;
    int columns;
    float income;
    cout << "Enter Type of Screening: ";
    cin >> screen;
    cout << "Enter Number of Rows: ";
    cin >> rows;
    cout << "Enter Number of Columns: ";
    cin >> columns;
    income = totalIncome(screen, rows, columns);
    cout << "Total Income is: " << income;
}
float totalIncome(string screen, int rows, int columns)
{
    float income;
    if (screen == "premiere")
    {
        income = 12.00 * rows * columns;
    }
    else if (screen == "normal")
    {
        income = 7.50 * rows * columns;
    }
    else if (screen == "discount")
    {
        income = 5.00 * rows * columns;
    }
    return income;
}