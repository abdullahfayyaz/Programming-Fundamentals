#include <iostream>
using namespace std;
string moves[10] = {"Shimmy", "Shake", "Pirouette", "Slide", "Box Step", "Headspin", "Dosado", "Pop", "Lock", "Arabesque"};
void danceMove(int position);
main()
{
    string pin;
    int pinlength, p = 0;
    cout << "Enter pin: ";
    cin >> pin;
    pinlength = pin.length();
    if (pinlength == 4)
    {
        int p1 = pin[0] - 48, p2 = pin[1] - 48, p3 = pin[2] - 48, p4 = pin[3] - 48;
        if ((p1 > -1 && p1 < 10) && (p2 > -1 && p2 < 10) && (p3 > -1 && p3 < 10) && (p4 > -1 && p4 < 10))
        {
            int position;
            position = 0;

            for (int i = 0; i < 4; i++)
            {
                p = pin[i] - 48;
                position = i + p;
                danceMove(position);
            }
        }
        else
        {
            cout << "Invalid input ";
        }
    }
    else
    {
        cout << "Invalid input ";
    }
}
void danceMove(int position)
{
    if (position <= 9)
    {
        cout << moves[position] << " ";
    }
    else if (position > 9)
    {
        position = position - 10;
        cout << moves[position] << " ";
    }
}