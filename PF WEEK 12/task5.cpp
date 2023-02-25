#include <fstream>
#include <iostream>
using namespace std;
main()
{
    string name;
    fstream file;
    file.open("text.txt", ios ::in);
    getline(file, name);
    file.close();
    cout << "The Line in file: " << name;
}