#include <iostream>
using namespace std;
main()
{
    int rollNo;
    string name;
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student roll number: ";
    cin >> rollNo;
    if (name == "ali")
    {
        if (rollNo == 501)
        {
            cout << "Congratulations Ali!" << endl;
        }
    }
}