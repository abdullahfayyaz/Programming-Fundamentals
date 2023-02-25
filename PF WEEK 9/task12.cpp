#include <iostream>
using namespace std;
main()
{
    int index = 0;
    char alphabets[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string word;
    cout << "Enter Word: ";
    cin >> word;
    while (word[index] != '\0')
    {
        for (int total = 0; total < 26; total++)
        {
            if (word[index] == alphabets[total])
            {
                int letter = total + 1;
                cout << alphabets[letter];
            }
        }
        index++;
    }
}