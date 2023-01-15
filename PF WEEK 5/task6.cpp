#include <iostream>
using namespace std;
main()
{
    int number;
	int position1;
	int position2;
	string ten;
	string unit;
	cout << "Enter a 2 digit number: ";
	cin >> number;
	position2 = number % 10;
	position1 = (number / 10) % 10;
	if(position1 == 0)
	{
	ten = "";
	}
	if(position1==2)
	{
	ten = "Twenty";
	}
	if(position1==3)
	{
	ten = "Thirty";
	}
	if(position1==4)
	{
	ten = "Fourty";
	}
	if(position1==5)
	{
	ten = "Fifty";
	}
	if(position1==6)
	{
	ten = "Sixty";
	}
	if(position1==7)
	{
	ten = "Seventy";
	}
	if(position1==8)
	{
	ten = "Eighty";
	}
	if(position1==9)
	{
	ten = "Ninety";
	}
	if(position2==0)
	{
	unit = "";
	}
	if(position2==1)
	{
	unit="One";
	}
	if(position2==2){
	unit = "Two";
	}
	if(position2==3)
	{
	unit = "Three";
	}
	if(position2==4)
	{
	unit = "Four";
	}
	if(position2==5)
	{
	unit = "Five";
	}
	if(position2==6)
	{
	unit = "Six";
	}
	if(position2==7)
	{
	unit = "Seven";
	}
	if(position2==8)
	{
	unit = "Eight";
	}
	if(position2==9)
	{
	unit = "Nine";
	}
	if(number == 10)
	{
		cout << "Ten";
	}
	cout<<ten<<" "<<unit;
}