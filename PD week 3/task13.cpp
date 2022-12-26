#include <iostream>
using namespace std;
main(){
      int marks1;
      int marks2;
      int marks3;
      int totalMarks;
      float percent1;
      float percent2;
      float percent3;
      float average;
      cout << "Enter Total Marks: ";
      cin >> totalMarks;                        
      cout << "Enter Marks of 1st Student: ";
      cin >> marks1;
      cout << "Enter Marks of 2nd Student: ";
      cin >> marks2;
      cout << "Enter Marks of 3rd Student: ";
      cin >> marks3;
      percent1 = marks1 * 100 / totalMarks;
      percent2 = marks2 * 100 / totalMarks;
      percent3 = marks3 * 100 / totalMarks;
      average = (percent1 + percent2 + percent3) / 3;
      cout << "Class Average: " << average;
}