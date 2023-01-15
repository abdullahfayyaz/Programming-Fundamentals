#include <iostream>
using namespace std;
string grade(float percentage);
main()
{
    string name;
    string result;
    float englishMarks;
    float mathsMarks;
    float chemistryMaths;
    float socialScienceMarks;
    float biologyMarks;
    float totalMarks;
    float percentage;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter English Marks: ";
    cin >> englishMarks;
    cout << "Enter Maths Marks: ";
    cin >> mathsMarks;
    cout << "Enter Chemistry Marks: ";
    cin >> chemistryMaths;
    cout << "Enter Social Science Marks: ";
    cin >> socialScienceMarks;
    cout << "Enter Biology Marks: ";
    cin >> biologyMarks;
    totalMarks = englishMarks + mathsMarks + chemistryMaths + socialScienceMarks + biologyMarks;
    percentage = totalMarks * 100 / 500;
    result = grade(percentage);
    cout << "Grade: " << result;
}
string grade(float percentage)
{
    string grade;
    if (percentage >= 90 && percentage <= 100)
    {
        grade = "A+";
    }
    else if (percentage >= 80 && percentage <= 90)
    {
        grade = "A";
    }
    else if (percentage >= 70 && percentage <= 80)
    {
        grade = "B+";
    }
    else if (percentage >= 60 && percentage <= 70)
    {
        grade = "B";
    }
    else if (percentage >= 50 && percentage <= 60)
    {
        grade = "C";
    }
    else if (percentage >= 40 && percentage <= 50)
    {
        grade = "D";
    }
    else
    {
        grade = "F";
    }
    return grade;
}