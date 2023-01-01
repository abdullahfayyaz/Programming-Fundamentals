#include <iostream>
using namespace std;

void calculateBill(string day, int amount);
main()
{
 string day;
 int amount;
 while(true)
 {
 cout << "Enter Day: ";
 cin >> day;
 cout << "Enter amount: ";
 cin >> amount;
 calculateBill(day, amount);
 }
}
void calculateBill(string day, int amount)
{
 float discount;
 discount = amount - (amount * 10/100); 
 if(day == "sunday")
 {
  cout << "Your payable amount is: " << discount << endl;
 }
 if(day != "sunday")
 {
  discount = amount - (amount * 5/100);
  cout << "Your payable amount is : " << discount << endl;
 }
}