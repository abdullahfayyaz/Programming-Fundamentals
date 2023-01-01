#include <iostream>
using namespace std;

void eligible(int age);
main()
{
  int age;
  while(true)
  {
   cout << "Enter your age: ";
   cin >> age;
   eligible(age);
  }
}
void eligible(int age)
{
  if(age >= 18)
  {
   cout << "You are Eligible" << endl;
  }	
  if(age < 18)
  {
   cout << "You are not Eligible" << endl;
  }
}
