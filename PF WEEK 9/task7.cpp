#include <iostream>
using namespace std;
main()
{
    bool found = false;
    string word;
    char letter;
    cout << "Enter Word: ";
    cin >> word;
    cout << "Enter Letter: ";
    cin >> letter;
    int index = 0;
    while (word[index] != '\0')
    {
        if (word[index] == letter)
        {
            found = true;
            break;
        }
        index++;
    }
    if (found == true)
    {
        cout << letter << " is found in " << word;
    }
    else
    {
        cout << letter << " is not found in " << word;
    }
}