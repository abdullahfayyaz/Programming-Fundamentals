#include <iostream>
using namespace std;
main(){
  float pounds;
  float kilogram;
  cout << "Enter weight in pounds: ";
  cin >> pounds;
  kilogram = 0.45 * pounds;
  cout << "Weight in kilograms: " << kilogram;
}