#include <iostream>
using namespace std;
int triangle(int number);
main()
{
    int number;
    int result;
    cout << "Enter Number: ";
    cin >> number;
    result = triangle(number);
    cout << "Number of dots: " << result;
}
int triangle(int number)
{
    int dot = 0;
    for (int i = 1; i <= number; i++)
    {
        dot = dot + i;
    }
    return dot;
}