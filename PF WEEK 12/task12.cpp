#include <iostream>
#include <fstream>
using namespace std;

string name[3];
int admissionNo[3];
float percentage[3];
int count = 0;
main()
{
    string studentName;
    int addmission_no;
    float percent;
    string change;
    fstream file;
    file.open("students.txt", ios::in);
    while (!file.eof())
    {
        file >> name[count];
        file >> admissionNo[count];
        file >> change;
        percent = stof(change);
        percentage[count] = percent;
        count++;
    }
    file.close();
    file.open("topperStudents.txt", ios::out);
    for (int i = 0; i < 3; i++)
    {
        if (percentage[i] > 60)
        {
            file << "Name: " << name[i] << endl;
            file << "Admission Number: " << admissionNo[i] << endl;
            file << "Percentage: " << percentage[i] << endl;
            file << endl;
        }
    }
    file.close();
}