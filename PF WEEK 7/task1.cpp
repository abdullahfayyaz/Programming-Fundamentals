#include <iostream>
using namespace std;
void printCounting();
int main()
{
    printCounting();
    return 0;
}
void printCounting()
{
    cout << "Counting (1 - 10)" << endl;
    for (int count = 1; count <= 10; count++)
    {
        cout << count << endl;
    }
}
