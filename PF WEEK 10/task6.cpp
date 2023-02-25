#include <iostream>
using namespace std;
main()
{
    int arrsize = 10;
    int package[arrsize];
    for (int index = 0; index < arrsize; index++)
    {
        cout << "Enter a number: ";
        cin >> package[index];
    }
    int temporary;
    for (int x = 0; x < arrsize; x++)
    {
        for (int i = x + 1; i < arrsize; i++)
        {
            if (package[x] > package[i])
            {
                temporary = package[x];
                package[x] = package[i];
                package[i] = temporary;
            }
        }
    }
    for (int x = 0; x < arrsize; x++)
    {
        cout << package[x] << " ";
    }
}