#include <iostream>
using namespace std;
main()
{
    int index = 0;
    int count = 0;
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    string word;
    cout << "Enter Word: ";
    cin >> word;
    while (word[index] != '\0')
    {
       
        for (int i = 0; i < 5; i++)
        {
            if (word[index] == vowels[i])
            {
                count++;
            }
        }
        index++;
    }
    cout << "Number Of Vowels: " << count;
}