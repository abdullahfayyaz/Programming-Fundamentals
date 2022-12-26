#include <iostream>
using namespace std;
main(){
       int date;
       string month;
       int year;
       int age;
       cout << "Enter date of birth: ";
       cin >> date;
       cout << "Enter month of birth: ";
       cin >> month;
       cout << "Enter year of birth: ";
       cin >> year;
       age = 2022 - year;
       cout << "Age in years: " << age;
}