#include<iostream>
using namespace std;
string smallCase(char character);
string capitalCase(char character);
main()
{
    char character;
    cout << "Enter Character: ";
    cin >> character;
    smallCase(character);
    capitalCase(character);
}
    string smallCase(char character)
    {
    if(character == 'a')
    {
        cout << "You have entered small a";
    }
    }
    string capitalCase(char character)
    {
    if(character == 'A')
    {
        cout << "You have entered Capital A";
    }
    }