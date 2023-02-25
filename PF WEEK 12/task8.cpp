#include <fstream>
#include <iostream>
using namespace std;
main()
{
    char character;
    int count = 0;
    fstream file;
    file.open("text.txt", ios ::in);
    while (!file.eof())
    {
        file >> character;
        count++;
    }
    file.close();
    cout << "Total Characters: " << count;
}