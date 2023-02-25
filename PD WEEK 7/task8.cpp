#include <iostream>
using namespace std;
main()
{
    float range, number;
    float cargo = 0;
    float avg;
    float totalsum;
    float minibus =0,truck = 0,train = 0;
    float result1,result2,result3;
    cout << "Enter range : ";
    cin >> range;
    for (int n=1 ; n <= range ; n++)
    {
        cout << "Enter cargo weight: ";
        cin >> number;
        cargo = cargo + number;
        if (number <= 3)
        {
            minibus = minibus +number;

        }
        if (number >3 && number <= 11)
        {
            truck = truck + number;

        }
        if (number > 11)
        {
            train = train + number;
        }
    }
    totalsum = minibus + truck + train;
    avg = (minibus * 200+truck * 175+train *120) / cargo; 
    result1 = minibus * 100 / cargo;
    result2 = truck * 100 / cargo;
    result3 = train * 100 / cargo;
   

    cout << avg << endl;
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;

}