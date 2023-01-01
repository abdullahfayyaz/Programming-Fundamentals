#include <iostream>
using namespace std;

void ticket(string country, float ticketPrice);
main()
{
 string country;
 float ticketPrice;
 while(true)
  {
   cout << "Enter Country Name: ";
   cin >> country;
   cout << "Enter Ticket Price in Dollars: ";
   cin >> ticketPrice;
   ticket(country,ticketPrice);
  }
}
void ticket(string country, float ticketPrice)
{
  float discount;
  if(country == "pakistan")
  {
   discount = ticketPrice - (ticketPrice * 5/100);
   cout << "Ticket Price After Discount: " << discount << endl;
  }
  if(country == "ireland")
  {
   discount = ticketPrice - (ticketPrice * 10/100);
   cout << "Ticket Price After Discount: " << discount << endl;
  }
  if(country == "india")
  {
   discount = ticketPrice - (ticketPrice * 20/100);
   cout << "Ticket Price After Discount: " << discount << endl;
  }
  if(country == "england")
  {
   discount = ticketPrice - (ticketPrice * 30/100);
   cout << "Ticket Price After Discount: " << discount << endl;
  }
  if(country == "canada")
  {
   discount = ticketPrice - (ticketPrice * 45/100);
   cout << "Ticket Price After Discount: " << discount << endl;
  }
}