#include <fstream>
#include <iostream>
using namespace std;
main()
{
    int count = 0;
    char letter;
    char character;
    fstream file;
    cout << "Enter letter: ";
    cin >> letter;
    file.open("story.txt", ios ::in);
    while (!file.eof())
    {
        file >> character;
        if (character == letter)
        {
            count++;
        }
    }
    file.close();
    cout << "Frequency of Character: " << count;
}