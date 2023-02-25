#include <iostream>
using namespace std;
main()
{
    string word;
    int length;
    cout << "Enter Word: ";
    cin >> word;
    length = word.length();
    for (int index = 0; index < length; index++)
    {
        cout << "Alphabet " << word[index] << " at the position: " << index << endl;
    }
}