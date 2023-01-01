#include <iostream>
using namespace std;
void change(string c);
main()
{
 string c;
 cout << "Enter either True or False: ";
 cin >> c;
 change(c);
}
void change(string c)
{
 if(c == "true")
  {
   cout << "False" << endl;
  }
 if(c == "false")
  {
   cout << "True" << endl;
  }
}
