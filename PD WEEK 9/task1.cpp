#include <iostream>
using namespace std;
main()
{
    bool found = false;
    string fruit_name;
    int quantity;
    int totalBill;
    string fruit[4] = {"peach", "apple", "guava", "watermelon"};
    int price[4] = {60, 70, 40, 30};
    cout << "Enter Fruit Name: ";
    cin >> fruit_name;
    cout << "Enter Quantity in kgs: ";
    cin >> quantity;
    for (int index = 0; index < 4; index++)
    {
        if (fruit_name == fruit[index])
        {
            totalBill = quantity * price[index];
            cout << "Fruit Name: " << fruit[index] << endl;
            cout << "Total Bill: " << totalBill;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Not Found";
    }
}