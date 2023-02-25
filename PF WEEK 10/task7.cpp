#include <iostream>
using namespace std;
main()
{
    int size;
    cout << "Enter No. of words: ";
    cin >> size;
    string word[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter word: ";
        cin >> word[index];
    }
    for (int index = size - 1; index > -1; index--)
    {
        cout << word[index] << " ";
    }
}