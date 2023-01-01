#include <iostream>
using namespace std;

void printName(string name);
main()
{
 string name;
 while(true)
 {
  cout <<"Enter your Name: ";
  cin >> name;
  printName(name);
 }
}
void printName(string name)
{
 if(name == "irzam")
 {
  while(true)
  {
  cout << "Your name is: " << name << endl;
  }
 }
 if(name != "irzam")
 {
  cout << "Your name is: " << name << endl;
 }
}