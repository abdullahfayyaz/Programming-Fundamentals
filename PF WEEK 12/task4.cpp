#include <fstream>
#include <iostream>
using namespace std;
main()
{
    string number1;
    string number2;
    char character;
    fstream file;
    file.open("number.txt", ios ::in);
    file >> number1;
    file >> number2;
    file >> character;
    file.close();
    cout << number1 << endl;
    cout << number2 << endl;
    cout << character << endl;
}