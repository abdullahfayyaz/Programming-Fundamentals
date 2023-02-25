#include <iostream>
using namespace std;
main()
{
    int count = 0;
    int length1;
    int length2;
    char compare;
    string element1;
    string element2;
    cout << "Enter Element 1: ";
    cin >> element1;
    cout << "Enter Element 2: ";
    cin >> element2;
    length1 = element1.length();
    length2 = element2.length();
    for (int index = 0; index < length1; index++)
    {
        compare = element1[index];
        for (int index = 0; index < length2; index++)
        {
            if (compare == element2[index])
            {
                count++;
                element2[index] = ' ';
                break;
            }
        }
    }
    cout << "Common Characters: " << count << endl;
}