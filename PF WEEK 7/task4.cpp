#include <iostream>
using namespace std;
void fibonacci(int number);
main()
{
    int number;
    int result;
    cout << "How many numbers of Fibonacci Series you want to print: ";
    cin >> number;
    fibonacci(number);
}
void fibonacci(int number)
{
    int number1 = 0;
    int number2 = 1;
    int result = 0;
    cout << "Fibonacci series: " << number1 << "," << number2;
    for (int count = 1; count <= number - 2; count++)
    {
        result = number1 + number2;
        cout << "," << result;
        number1 = number2;
        number2 = result;
    }
}
