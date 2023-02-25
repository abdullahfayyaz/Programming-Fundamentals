#include <iostream>
using namespace std;
int showSum();
main()
{
    int total;
    total = showSum();
    cout << "Sum: " << total << endl;
}
int showSum()
{
    int sum = 0;
    for (int number = 1; number <= 5; number = number + 1)
    {
        sum = sum + number;
    }
    return sum;
}
