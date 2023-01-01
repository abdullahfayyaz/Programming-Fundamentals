#include <iostream>
using namespace std;

void add(int number1, int number2);
main()
{
  int number1;
  int number2;
  while(true)
  {
  cout << "Enter 1st Number: ";
  cin >> number1;
  cout << "Enter 2nd Number: ";
  cin >> number2;
  add(number1,number2);
  }  
}
void add(int number1, int number2)
{
  int sum = number1 + number2;
  cout << "Sum is: " << sum << endl;
}