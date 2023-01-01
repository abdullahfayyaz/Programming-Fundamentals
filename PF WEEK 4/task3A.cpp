#include <iostream>
using namespace std;

void checkResult(int marks);
main()
{
 int marks;
 cout << "Enter your marks: ";
 cin >> marks;
 checkResult(marks);
}
void checkResult(int marks)
{
  if(marks >= 50)
  {
   cout << "Passed" << endl;
  }	
  if(marks < 50)
  {
   cout << "Fail" << endl;
  }
}
