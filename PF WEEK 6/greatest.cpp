#include <iostream>
using namespace std;

int isGreatest(int number1, int number2, int number3);

main()
{
    int number1, number2, number3;
    int greatest;
    cout << "Enter 1st Number: ";
    cin >> number1;
    cout << "Enter 2nd Number: ";
    cin >> number2;
    cout << "Enter 3rd Number: ";
    cin >> number3;
    greatest = isGreatest(number1, number2, number3);
    cout << "Greatest Number is: " << greatest;
}
int isGreatest(int number1, int number2, int number3)
{
    int greatest;
    if (number1 > number2 && number1 > number3)
    {
        greatest = number1;
    }
    if (number2 > number1 && number2 > number3)
    {
        greatest = number2;
    }
    if (number3 > number1 && number3 > number2)
    {
        greatest = number3;
    }
    return greatest;
}
