#include <iostream>
#include <cmath>
using namespace std;
bool isSymmetrical(int number, int position1,int position2, int position3);
main()
{
     int number;
     int position1;
     int position2;
     int position3;
     bool Symmetrical;
     cout << "Enter Three Digit Number: ";
     cin >> number;
     position1 = number % 10;
     number = number / 10;
     position2 = number % 10;
     position3 = number / 10;
     Symmetrical = isSymmetrical(number, position1, position2, position3);
     if(Symmetrical == true)
     {
        cout << "It is a Symmetrical Number";
     }
     if(Symmetrical == false)
     {
        cout << "It is not a Symmetrical Number";
     }
}
bool isSymmetrical(int number, int position1, int position2, int position3)
{
 if(position1 == position3)
 {
    return true;
 }
 if(position1 != position3)
 {
    return false;
 }
}


 
