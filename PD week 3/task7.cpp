#include <iostream>
using namespace std;
main(){
       string movieName;
       float adultTicketPrice;
       float childTicketPrice;
       int adultTicketSold;
       int childTicketSold;
       float totalAmount;
       float amountAfterDonation;
       float percentage;
       cout << "Enter Movie Name: ";
       cin >> movieName;
       cout << "Enter Adult Ticket Price: ";
       cin >> adultTicketPrice;
       cout << "Enter Child Ticket Price: ";
       cin >> childTicketPrice;
       cout << "Enter Number of Adult Ticket Sold: ";
       cin >> adultTicketSold;
       cout << "Enter Number of Child Ticket Sold: ";
       cin >> childTicketSold;
       cout << "Enter Percentage to Donate: ";
       cin >> percentage;
       totalAmount = (adultTicketPrice * adultTicketSold) + (childTicketPrice * childTicketSold); 
       amountAfterDonation = totalAmount - (totalAmount * percentage/100);
       cout << "_________________________________________________________________________________" << endl;
       cout << "Total Amount Generated: " << totalAmount << endl;
       cout << "Amount After Donation: " << amountAfterDonation;
}
       
       
       
       
       
