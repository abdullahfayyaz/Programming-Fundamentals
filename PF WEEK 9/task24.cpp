#include <iostream>
using namespace std;
main()
{
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    for (int index = 0; word[index] != '\0'; index++)
    {
        if (word[index] == 'a' || word[index] == 'e' || word[index] == 'i' || word[index] == 'o' || word[index] == 'u')
        {
            continue;
        }
        else
        {
            cout << word[index];
        }
    }
}