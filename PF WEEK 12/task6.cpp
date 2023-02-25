#include <fstream>
#include <iostream>
using namespace std;
main()
{
    string line;
    fstream file;
    file.open("text.txt", ios ::in);
    while (!file.eof())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}