#include <iostream>
using namespace std;

void displayDetails(string name, int marks, char section, float aggregate);
main()
{
  string name;
  char section;
  int marks;
  float aggregate;
  cout << "Enter your Name: ";
  cin >> name;
  cout << "Enter your Marks: ";
  cin >> marks;
  cout << "Enter your section: ";
  cin >> section;
  cout << "Enter your Aggregate: ";
  cin >> aggregate;
  displayDetails(name, marks, section, aggregate);	
}
void displayDetails(string name, int marks, char section, float aggregate)
{
  cout << "------------------------------------------" << endl;
  cout << "Your Name is: " << name << endl;
  cout << "Your Marks is: " << marks << endl;
  cout << "Your section is: " << section << endl;
  cout << "YOur Aggregate is: " << aggregate << endl;
}

