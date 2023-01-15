#include <iostream>
#include <cmath>
using namespace std;
string isEvenish(int number);
string isOddish(int number);
main()
{
    int number;
    int sum;
    int result;
    int position1;
    int position2;
    int position3;
    int position4;
    int position5;
    cout << "Enter Five Digit Number: ";
    cin >> number;
    position1 = number % 10;
    number = number / 10;
    position2= number % 10;
    number = number / 10;
    position3 = number % 10;
    number = number / 10;
    position4 = number % 10;
    position5 = number / 10;
    sum = position1 + position2 + position3 + position4 + position5;
    result = sum;
    isEvenish(result);
    isOddish(result);
}
string isEvenish(int number)
{
 int result;
 if(result % 2 == 0)
 {
 cout << "Number is Evenish" << endl;
 }
}
string isOddish(int number)
{
 int result;
 if(result % 2 != 0)
 {
 cout << "Number is Oddish" << endl;
 }
}
 
