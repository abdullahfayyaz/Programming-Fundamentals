#include <iostream>
using namespace std;
main()
{
    int size;
    int count = 0;
    char letter;
    cout << "Enter how many words you want to Enter: ";
    cin >> size;
    cout << "Enter the letter you want to find: ";
    cin >> letter;
    char word[size];
    for (int index = 0; index < size; index++)
    {
        cout << "Enter Word: ";
        cin >> word;
        for (int x = 0; word[x] != '\0'; x++)
        {
            if (word[x] == letter)
            {
                count++;
            }
        }
    }
    cout << letter << " shows up " << count << " times in the data.";
}