#include <iostream>
using namespace std;

void header();
void printMenu();
void calculateAggregate();
void compareMarks();
main()
{
  system("cls");
  header();
  printMenu();
  int option;
  cout << "Enter Option Number: ";
  cin >> option;
  if(option == 1)
  {
   calculateAggregate();
  }
  if(option == 2)
  {
   compareMarks();
  }
}
void header()
{
  cout << " **********************************************   " << endl;
  cout << " *   University Admission Management System   *   " << endl;
  cout << " **********************************************   " << endl;
}
void printMenu()
{
  cout << "Main Menu >" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Select one of the following options number..." << endl;
  cout << "1- Calculate Aggregate" << endl;
  cout << "2- Compare Marks" << endl;
}
void calculateAggregate()
{
  system("cls");
  string name;
  float matricMarks;
  float aggregate;
  float interMarks;
  float ecatMarks;
  header();
  cout << "Main Menu > Calculate Aggregate" << endl;
  cout << "----------------------------------------------" << endl;
  cout << "Enter Student Name: ";
  cin >> name;
  cout << "Enter Student Matric Marks: ";
  cin >> matricMarks;
  cout << "Enter Student Intermediate Marks: ";
  cin >> interMarks;
  cout << "Enter Student Ecat Marks: ";
  cin >> ecatMarks;
  aggregate = (matricMarks / 1100) * 30 + (interMarks / 550) * 30 + (ecatMarks / 400) * 40;  
  cout << "Student Aggregate: " << aggregate;
}
void compareMarks()
{
   system("cls");
   header();
   string nameStd1;
   string nameStd2;
   float ecatMarksStd1;
   float ecatMarksStd2;
   cout << "Main Menu > Compare Marks" << endl;
   cout << "----------------------------------------------" << endl;
   cout << "Enter Student Name: ";
   cin >> nameStd1;
   cout << "Enter Student Ecat Marks: ";
   cin >> ecatMarksStd1;
   cout << "Enter Student Name: ";
   cin >> nameStd2;
   cout << "Enter Student Ecat Marks: ";
   cin >> ecatMarksStd2;
   cout << "----------------------------------------------" << endl;
  if(ecatMarksStd1 > ecatMarksStd2)
  {
   cout << "Roll Number 1     " << nameStd1 << endl;
   cout << "Roll Number 2     " << nameStd2 << endl;
  }
  if(ecatMarksStd1 < ecatMarksStd2)
  {
   cout << "Roll Number 1     " << nameStd2 << endl;
   cout << "Roll Number 2     " << nameStd1 << endl;
  }
}
