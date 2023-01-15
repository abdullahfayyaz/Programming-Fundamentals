#include <iostream>
using namespace std;
float taxCalculator(char type, float price);
main()
{
    float taxRate;
    char type;
    float price;
    float finalPrice;
    cout << "Enter Item Price: ";
    cin >> price;
    cout << "Enter Vehicle Type: ";
    cin >> type;
    finalPrice = taxCalculator(type, price);
    cout << "The final price on a vehicle of type " << type << " after adding the tax is $" << finalPrice;
}
float taxCalculator(char type, float price)
{
    float taxAmount;
    if (type == 'M')
    {
        taxAmount = price * (6.0 / 100);
        return taxAmount;
    }
    if (type == 'E')
    {
        taxAmount = price * (8.0 / 100);
        return taxAmount;
    }
    if (type == 'S')
    {
        taxAmount = price * (10.0 / 100);
        return taxAmount;
    }
    if (type == 'V')
    {
        taxAmount = price * (12.0 / 100);
        return taxAmount;
    }
    if (type == 'T')
    {
        taxAmount = price * (15.0 / 100);
        return taxAmount;
    }
}
