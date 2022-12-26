#include <iostream>
using namespace std;
main(){
  int dollar = 200;
  int inputValue;
  int convertedValue;
  cout << "$1 = " << dollar << " rupees" << endl;
  cout << "Enter Value: ";
  cin >> inputValue;
  convertedValue = dollar * inputValue;
  cout << "Converted Value in Rupees is: " << convertedValue;
} 