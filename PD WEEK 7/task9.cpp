#include <iostream>
using namespace std;
void oppositeSide(int rows);
main()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
    oppositeSide(rows);
}
void oppositeSide(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = i; j <= rows; j++)
        {
            cout << " ";
        }
        for (int j = i; j <= rows; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
