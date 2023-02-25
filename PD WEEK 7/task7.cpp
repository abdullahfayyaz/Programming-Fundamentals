#include <iostream>
using namespace std;
main()
{
    int range;
    int number;
    int c1, c2, c3;
    float p1, p2, p3;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    cout << "Enter a range : ";
    cin >> range;
    for (int n = 1; n <= range; n++)
    {
        cout << "Enter a number: ";
        cin >> number;
        if (number % 2 == 0)
        {
            c1++;
        }
        if (number % 3 == 0)
        {
            c2++;
        }
        if (number % 4 == 0)
        {
            c3++;
        }
    }
    p1 = c1 * 100 / range;
    p2 = c2 * 100 / range;
    p3 = c3 * 100 / range;
    cout << p1 << " %" << endl;
    cout << p2 << " %" << endl;
    cout << p3 << " %" << endl;
}