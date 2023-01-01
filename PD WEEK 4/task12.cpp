#include <iostream>
using namespace std;

void flowers(float redRose, float whiteRose, float tulips);
main()
{
 float redRose;
 float whiteRose;
 float tulips;
 cout << "Enter Number of Red Rose: ";
 cin >> redRose;
 cout << "Enter Number of White Rose: ";
 cin >> whiteRose;
 cout << "Enter Number of Tulips: ";
 cin >> tulips;
 flowers(redRose, whiteRose, tulips);
}
void flowers(float redRose, float whiteRose, float tulips)
{
  float discount;
  float totalPrice;
  redRose = redRose * 2.00;
  whiteRose = whiteRose * 4.10;
  tulips = tulips * 2.50;
  totalPrice = redRose + whiteRose + tulips;
  cout << "Original price: " << totalPrice << endl;
   if(totalPrice > 200)
    {
     discount = totalPrice - (totalPrice * 20/100);
     cout<<"Price after Discount: " << discount;
    }
}



