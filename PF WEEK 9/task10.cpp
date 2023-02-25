#include <iostream>
using namespace std;
main()
{
    string word;
    int length;
    cout << "Enter Word: ";
    cin >> word;
    length = word.length();
    for (int index = length - 1; index >= 0; index--)
    {
        cout << word[index];
    }
}