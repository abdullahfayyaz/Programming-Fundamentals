#include <iostream>
using namespace std;
main(){
  string name;
  float matric;
  float floatermediate;
  float ecat;
  float aggregate;
  cout << "Enter Name: ";
  cin >> name;
  cout << "Enter your marks in Matric: ";
  cin >> matric;
  cout << "Enter your marks in 1st year: ";
  cin >> floatermediate;
  cout << "Enter your marks in Ecat: ";
  cin >> ecat;
  aggregate = (matric / 1100) * 10 + (floatermediate / 550) * 40 + (ecat / 400) * 50;  
  cout << "Your Aggregate is: " << aggregate;
}