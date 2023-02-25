#include <fstream>
#include <iostream>
using namespace std;
main()
{
    int number;
    float number2;
    char character;
    fstream file;
    cout << "Enter Number: ";
    cin >> number;
    cout << "Enter Number 2: ";
    cin >> number2;
    cout << "Enter Character: ";
    cin >> character;
    file.open("number.txt", ios ::out);
    file << number << endl;
    file << number2 << endl;
    file << character << endl;
    file.close();
}