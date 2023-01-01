#include <iostream>
using namespace std;
void maximum(int number1, int number2);
void minimum(int number1, int number2);
void isEqual(int number1, int number2);
main()
{
 int number1;
 int number2;
 int choice;
 cout << "Enter 1st Number: ";
 cin >> number1;
 cout << "Enter 2nd Number: ";
 cin >> number2;
 cout << "CHOICE:" << endl;
 cout << "1.Greater Number" << endl;
 cout << "2.Lesser Number" << endl;
 cout << "3.Equal or Not" << endl;
 cout << "Enter choice(1-3): ";
 cin >> choice;
 if(choice == 1)
 {
   maximum(number1, number2);  
 }
 if(choice == 2)
 {
   minimum(number1, number2);
 }
 if(choice == 3)
 {  
 isEqual(number1, number2);
 }
}
void maximum(int number1, int number2)
{
 if(number1 > number2)
 {
  cout << "Greater Number is: " << number1 << endl;
 }
 if(number2 > number1)
 {
  cout << "Greater Number is: " << number2 << endl;
 }
}
void minimum(int number1, int number2)
{
 if(number1 < number2)
 {
 cout << "Lesser Number is: " << number1 << endl;
 }
 if(number2 < number1)
 {
  cout << "Lesser Number is: " << number2 << endl;
 }
}
void isEqual(int number1, int number2)
{
 if(number1 == number2)
 {
  cout << "Numbers are equal" << endl; 
 }
 if(number1 != number2)
 {
  cout << "Numbers are not equal" << endl;
 }
}

