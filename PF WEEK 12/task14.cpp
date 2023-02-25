#include <iostream>
#include <fstream>
using namespace std;
main()
{
    string word;
    fstream file;
    int length;
    char character;
    file.open("story.txt", ios ::in);
    while (!file.eof())
    {
        file >> word;
        length = word.length();
        if (length < 4)
        {
            cout << word << endl;
        }
    }
    file.close();
}