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
    for (int number = 1; number <= 100; number++)
    {
        sum = sum + number;
    }
    return sum;
}
