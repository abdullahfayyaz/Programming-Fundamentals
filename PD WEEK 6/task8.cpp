#include <iostream>
using namespace std;
main()
{
    int h;
    int x, y;
    cout << "Enter the height: ";
    cin >> h;
    cout << "Enter x coordinate of point: ";
    cin >> x;
    cout << "Enter y coordinate of point: ";
    cin >> y;
    if ((x >= 0 && x <= 3 * h) && (y == 0))
    {
        cout << "Border";
    }
    else if ((x >= 0 && x <= h) && (y == h))
    {
        cout << "Border";
    }
    else if ((x >= 2 * h && x <= 3 * h) && (y == h))
    {
        cout << "Border";
    }
    else if (x == h && (y >= h && y <= 4 * h))
    {
        cout << "Border";
    }
    else if (x == 2 * h && (y >= h && y <= 4 * h))
    {
        cout << "Border";
    }
    else if (x == 0 && (y >= 0 && y <= h))
    {
        cout << "Border";
    }
    else if (x == 3 * h && (y >= 0 && y <= h))
    {
        cout << "Border";
    }
    else if ((x >= h && x <= 2 * h) && y == 4 * h)
    {
        cout << "Border";
    }
    else if ((x < 0) || (x > 3 * h))
    {
        cout << "Outside";
    }
    else if ((x < h) || (y > h))
    {
        cout << "Outside";
    }
    else if ((x > 2 * h) || (y > h))
    {
        cout << "Outside";
    }
    else if ((y < 0) || (y > 4 * h))
    {
        cout << "Outside";
    }
    else
    {
        cout << "Inside";
    }
}