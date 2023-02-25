#include <iostream>
#include <fstream>
using namespace std;
main()
{
    string line;
    fstream file;
    char character;
    int count = 0;
    file.open("story.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        if (line[0] != 'T')
        {
            count++;
        }
    }
    file.close();
    cout << "Total lines: " << count;
}