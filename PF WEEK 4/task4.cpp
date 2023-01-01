#include <iostream>
using namespace std;
main()
{
 int number;
 cout << "Enter Number: ";
 cin >> number;
 if(number % 2 == 0)
 {
  cout << "It's an even number" << endl;
 }	
 if(number % 2 != 0)
 {
  cout << "It's an odd number" << endl;
 }
}