#include <iostream>
using namespace std;
void pattern(int rows);
main()
{
    int rows;
    cout << "Enter desired number of rows: ";
    cin >> rows;
    pattern(rows);
}
void pattern(int rows)
{

    {
        for (int c = rows; c >= 0; c--)
        {
            for (int j = 1; j <= c; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
}