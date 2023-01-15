#include<iostream>
using namespace std;

int myFunction(int number);
main()
{
    int number;
    int result;
    cout << "Enter Number: ";
    cin >> number;
    result = myFunction(number);
    cout << "Result is: " << result;
    return 0;
}
int myFunction(int number)
{
    int total;
    total = number * 5;
    return total;
}