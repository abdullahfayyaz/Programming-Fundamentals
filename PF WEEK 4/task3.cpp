#include <iostream>
using namespace std;
main()
{
  int marks;
  cout << "Enter your marks: ";
  cin >> marks;
  if(marks >= 50)
  {
    cout << "Passed" << endl;
  }	
  if(marks < 50)
  {
    cout << "Fail" << endl;
  }
}
