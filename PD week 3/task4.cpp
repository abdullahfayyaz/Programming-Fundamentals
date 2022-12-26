#include <iostream>
using namespace std;
main(){
       string name;
       int totalMarks = 500;
       float obtainedMarks;
       float physics;
       float maths;
       float computer;
       float urdu;
       float english;
       float percentage;
       cout << "Enter Your Name: ";
       cin >> name;
       cout << "Enter Physics Marks: ";
       cin >> physics;
       cout << "Enter Maths Marks: ";
       cin >> maths;
       cout << "Enter Computer Science Marks: ";
       cin >> computer;
       cout << "Enter Urdu Marks: ";
       cin >> urdu;
       cout << "Enter English Marks: ";
       cin >> english;
       obtainedMarks = physics + maths + computer + urdu + english;
       percentage = (obtainedMarks * 100) / totalMarks;
       cout << "Your Percentage: " << percentage;
}

      
