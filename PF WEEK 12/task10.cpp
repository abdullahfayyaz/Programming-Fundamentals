#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

string studentName[100];
int studentAge[100];
int matricMarks[100];
int fscMarks[100];
int ecatMarks[100];
int count = 0;

int menu();
void addStudent(string name, int age, int matric, int fsc, int ecat);
void viewStudents();
void storeData(string name, int age, int matric, int fsc, int ecat);
void loadData();
main()
{
    loadData();
    int choice = 0;
    string name;
    int age;
    int matric;
    int fsc;
    int ecat;
    while (choice != 3)
    {
        choice = menu();
        if (choice == 1)
        {
            system("cls");
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Matric marks: ";
            cin >> matric;
            cout << "Enter Fsc marks: ";
            cin >> fsc;
            cout << "Enter Ecat Marks: ";
            cin >> ecat;
            addStudent(name, age, matric, fsc, ecat);
            storeData(name, age, matric, fsc, ecat);
        }
        else if (choice == 2)
        {
            viewStudents();
        }
        else if (choice == 3)
        {
            return 0;
        }
    }
}
int menu()
{
    system("cls");
    int option;
    cout << "1. Add Student" << endl;
    cout << "2. View Student" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Enter the Option Number: ";
    cin >> option;
    return option;
}
void addStudent(string name, int age, int matric, int fsc, int ecat)
{
    studentName[count] = name;
    studentAge[count] = age;
    matricMarks[count] = matric;
    fscMarks[count] = fsc;
    ecatMarks[count] = ecat;
    count++;
}
void storeData(string name, int age, int matric, int fsc, int ecat)
{
    fstream storeData;
    storeData.open("studentRecord.txt", ios::app);
    storeData << name << endl;
    storeData << age << endl;
    storeData << matric << endl;
    storeData << fsc << endl;
    storeData << ecat << endl;
    storeData.close();
}
void loadData()
{
    string name;
    string age;
    string matric;
    string fsc;
    string ecat;
    fstream load_data;
    int index = 0;
    load_data.open("studentrecord.txt", ios::in);
    while (getline(load_data, name) && getline(load_data, age) && getline(load_data, matric) && getline(load_data, fsc) && getline(load_data, ecat))
    {
        studentName[index] = name;
        studentAge[index] = stoi(age);
        matricMarks[index] = stoi(matric);
        fscMarks[index] = stoi(fsc);
        ecatMarks[index] = stoi(ecat);
        index++;
    }
    load_data.close();
    count = index;
}
void viewStudents()
{
    system("cls");
    cout << "Student Name"
         << "\t"
         << "Age"
         << "\t"
         << "Matric Marks"
         << "\t"
         << "Fsc Marks"
         << "\t"
         << "Ecat Marks" << endl;
    for (int x = 0; x < count; x++)
    {
        cout << studentName[x] << "\t\t" << studentAge[x] << "\t" << matricMarks[x] << "\t\t" << fscMarks[x] << "\t\t" << ecatMarks[x] << endl;
    }
    cout << endl;
    cout << " Press any key to continue";
    getch();
}