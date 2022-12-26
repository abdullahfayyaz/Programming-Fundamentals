#include <iostream>
using namespace std;
main(){
       int number;
       int position1;
       int position2;
       int position3;
       int position4;
       int result1;
       int result2;
       int sum;
       cout << "Enter four digit Number: ";
       cin >> number;
       position4 = number % 10;
       number = number / 10;
       position3 = number % 10;
       number = number / 10;
       position2 = number % 10;
       number = number / 10;
       position1 = number % 10;
       number = number / 10;
       result1 = position1 + position3;
       result2 = position2 * position4; 
       sum = result1 + result2;
       cout << "Sum: " << sum;       
}