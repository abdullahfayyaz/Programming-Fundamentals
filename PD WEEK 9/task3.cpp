#include <iostream>
using namespace std;
main()
{
    int count = 0;
    string word;
    cout << "Enter Word: ";
    cin >> word;
    for (int index = 0; word[index] != 0; index++)
    {
        count++;
    }
    if (count % 2 == 0)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}