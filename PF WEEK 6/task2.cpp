#include <iostream>
using namespace std;
string checkTitle(float age, char gender);
main()
{
    float age;
    char gender;
    string title;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin >> gender;
    title = checkTitle(age, gender);
    cout << "Title is: " << title;
}
string checkTitle(float age, char gender)
{
    string title;
    if (age >= 16 && gender == 'm')
    {
        title = "Mr.";
    }
    else if (age < 16 && gender == 'm')
    {
        title = "Master";
    }
    else if (age >= 16 && gender == 'f')
    {
        title = "Ms.";
    }
    else if (age < 16 && gender == 'f')
    {
        title = "Miss";
    }
    return title;
}