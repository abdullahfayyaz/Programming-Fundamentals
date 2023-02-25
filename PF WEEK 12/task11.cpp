#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

const int total = 100;
string userName[total];
string passwordA[total];
string roles[total];
int userCount = 0;

void clear();
int menu();
bool signUp(string name, string password);
string signIn(string name, string password);
bool isValid(string username);
void storeUser(string name, string password);
void loadUser();
void viewAllUsers();
main()
{
    loadUser();
    int choice = 0;
    bool isCheck;
    string name;
    string password;
    string role;
    while (choice != 3)
    {
        choice = menu();
        if (choice == 1)
        {
            system("cls");
            cout << "Enter User Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            isCheck = signUp(name, password);
            if (isCheck == true)
            {
                storeUser(name, password);
                cout << "Successfully Signed Up" << endl;
                clear();
            }
            else if (isCheck == false)
            {
                cout << "Already Exist" << endl;
                clear();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            cout << "Enter User Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            isCheck = isValid(name);
            if (isCheck == true)
            {
                role = signIn(name, password);
                if (role == "manager")
                {
                    cout << "Manager Menu" << endl;
                    clear();
                }
                else if (role == "customer")
                {
                    cout << "Customer Menu" << endl;
                    clear();
                }
                else
                {
                    cout << " Sign Up First";
                }
            }
        }
        else if (choice == 3)
        {
            viewAllUsers();
        }
        else if (choice == 4)
        {
            return 0;
        }
    }
}
void clear()
{
    cout << "Press any key to continue: ";
    getch();
    system("cls");
}
int menu()
{
    int option;
    cout << "1. Sign Up " << endl;
    cout << "2. Sign In " << endl;
    cout << "3. View All Users " << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your Option: ";
    cin >> option;
    return option;
}
bool signUp(string name, string password)
{
    bool isNew = true;
    for (int index = 0; index < userCount; index++)
    {
        if (userName[index] == name || passwordA[index] == password)
        {
            isNew = false;
        }
    }
    if (isNew == true)
    {
        userName[userCount] = name;
        passwordA[userCount] = password;
        roles[userCount] = "customer";
        userCount++;
    }
    return isNew;
}
void storeUser(string name, string password)
{
    fstream userInfo;
    userInfo.open("userRecord.txt", ios::app);
    userInfo << name << endl;
    userInfo << password << endl;
    userInfo << "customer" << endl;
    userInfo.close();
}
void loadUser()
{
    fstream loadData;
    int index = 0;
    loadData.open("userRecord.txt", ios::in);
    {
        while (!loadData.eof())
        {
            loadData >> userName[index];
            loadData >> passwordA[index];
            loadData >> roles[index];
            index++;
        }
    }
    loadData.close();
    userCount = index;
}
void viewAllUsers()
{
    cout << "User Name"
         << "\t"
         << "Password"
         << "\t"
         << "Role" << endl;
    for (int index = 0; index < userCount; index++)
    {
        cout << userName[index] << "\t\t" << passwordA[index] << "\t\t" << roles[index] << endl;
    }
}
bool isValid(string username)
{
    bool isFound = false;
    for (int index = 0; index < userCount; index++)
    {
        if (userName[index] == username)
        {
            isFound = true;
        }
    }
    return isFound;
}
string signIn(string name, string password)
{
    string role = "undefined";
    for (int index = 0; index < userCount; index++)
    {
        if (userName[index] == name && passwordA[index] == password)
        {
            return roles[index];
        }
    }
    return role;
}
