#include <iostream>
using namespace std;
main()
{
    string name;
    char letter;
    int index = 0;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Letter: ";
    cin >> letter;
    while (name[index] != '\0')
    {
        index++;
    }
    index--;
    if (name[index] == letter)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}