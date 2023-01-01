#include <iostream>
using namespace std;
main()
{
 string day;
 int amount;
 float discount;
 cout << "Enter Day: ";
 cin >> day;
 cout << "Enter amount: ";
 cin >> amount;
 discount = amount - (amount * 10/100); 
 if(day == "sunday")
 {
  cout << "Your payable amount after discount is: " << discount << endl;
 }
 if(day != "sunday")
 {
  cout << "Your payable amount is : " << amount << endl;
 }
}