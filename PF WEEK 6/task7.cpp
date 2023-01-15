#include <iostream>
using namespace std;
float checkCost(string city, string product, int quantity);
main()
{
    string city;
    string product;
    int quantity;
    float cost;
    cout << "Enter Product: ";
    cin >> product;
    cout << "Enter City Name: ";
    cin >> city;
    cout << "Enter Product Quantity: ";
    cin >> quantity;
    cost = checkCost(city, product, quantity);
    cout << "Total Cost: " << cost;
}
float checkCost(string city, string product, int quantity)
{
    float cost;
    if (product == "coffee")
    {
        if (city == "sofia")
        {
            cost = quantity * 0.50;
        }
        else if (city == "plovdiv")
        {
            cost = quantity * 0.40;
        }
        else if (city == "varna")
        {
            cost = quantity * 0.45;
        }
    }
    else if (product == "water")
    {
        if (city == "sofia")
        {
            cost = quantity * 0.80;
        }
        else if (city == "plovdiv")
        {
            cost = quantity * 0.70;
        }
        else if (city == "varna")
        {
            cost = quantity * 0.70;
        }
    }
    else if (product == "beer")
    {
        if (city == "sofia")
        {
            cost = quantity * 1.20;
        }
        else if (city == "plovdiv")
        {
            cost = quantity * 1.15;
        }
        else if (city == "varna")
        {
            cost = quantity * 1.10;
        }
    }
    else if (product == "sweets")
    {
        if (city == "sofia")
        {
            cost = quantity * 1.45;
        }
        else if (city == "plovdiv")
        {
            cost = quantity * 1.30;
        }
        else if (city == "varna")
        {
            cost = quantity * 1.35;
        }
    }
    else if (product == "peanuts")
    {
        if (city == "sofia")
        {
            cost = quantity * 1.60;
        }
        else if (city == "plovdiv")
        {
            cost = quantity * 1.50;
        }
        else if (city == "varna")
        {
            cost = quantity * 1.55;
        }
    }
    return cost;
}