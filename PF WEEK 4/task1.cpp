#include <iostream>
using namespace std;

void add(float number1, float number2);
void multiply(float number1, float number2);
void divide(float number1, float number2);
void subtract(float number1, float number2);
main()
{
 float number1;
 float number2;
 char operation;
 while(true)
 {
  cout << "Enter 1st Number: ";
  cin >> number1;
  cout << "Enter 2nd Number: ";
  cin >> number2;
  cout << "Enter operator(+,*,/,-): ";
  cin >> operation;
  if(operation == '+')
  {
   add(number1,number2);	
  }
  if(operation == '*')
  {
   multiply(number1,number2);
  }
  if(operation == '/')
  {
   divide(number1,number2);
  }
  if(operation == '-')
  {
   subtract(number1,number2);
  }
 }
}
void add(float number1, float number2)
{
  float sum = number1 + number2;
  cout << "Sum is: " << sum << endl;
}
void multiply(float number1, float number2)
{
  float product = number1 * number2;
  cout << "Product is: " << product << endl;
}
void divide(float number1, float number2)
{
  float divide = number1 / number2;
  cout << "Division is : " << divide << endl;
}
void subtract(float number1, float number2)
{
  float subtract = number1 - number2;
  cout << "Subtraction is: " << subtract << endl;
}