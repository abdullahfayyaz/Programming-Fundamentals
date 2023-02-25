#include <iostream>
using namespace std;
void upperPart(int rows);
void lowerPart(int rows);
main()
{
    int rows;
    cout << "Enter desired number of rows: ";
    cin >> rows;
    upperPart(rows);
    lowerPart(rows);
}
void upperPart(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = i; j <= rows; j++)
        {
            cout << " ";
        }
        for (int s = 1; s <= i; s++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void lowerPart(int rows)
{
    for (int i = rows; i >= 1; i--)
    {
        for (int j = i; j <= rows; j++)
        {
            cout << " ";
        }
        for (int s = 1; s <= i; s++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
