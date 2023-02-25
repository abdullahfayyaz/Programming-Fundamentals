#include <fstream>
#include <iostream>
using namespace std;
main()
{
    string line;
    int count = 0;
    fstream file;
    file.open("text.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        count++;
    }
    file.close();
    cout << "Total Lines: " << count;
}