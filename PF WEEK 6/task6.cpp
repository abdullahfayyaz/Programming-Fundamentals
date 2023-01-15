#include <iostream>
using namespace std;
float lowestPrice(int kilometers, string travelTime);
main()
{
    string travelTime;
    int kilometers;
    float price;
    cout << "Enter Kilometers (1 - 5000): ";
    cin >> kilometers;
    cout << "Enter Travel Time (day or night): ";
    cin >> travelTime;
    price = lowestPrice(kilometers, travelTime);
    cout << "Lowest Price: " << price;
}
float lowestPrice(int kilometers, string travelTime)
{
    float taxiPrice;
    float busPrice;
    float trainPrice;
    if (travelTime == "day" && (kilometers >= 20 && kilometers < 100))
    {
        taxiPrice = 0.70 + 0.79 * kilometers;
        busPrice = 0.09 * kilometers;
        if (taxiPrice < busPrice)
        {
            return taxiPrice;
        }
        else
        {
            return busPrice;
        }
    }
    else if (travelTime == "day" && kilometers >= 100)
    {
        taxiPrice = 0.70 + 0.79 * kilometers;
        trainPrice = 0.06 * kilometers;
        if (taxiPrice < trainPrice)
        {
            return taxiPrice;
        }
        else
        {
            return trainPrice;
        }
    }
    else if (travelTime == "day")
    {
        taxiPrice = 0.70 + 0.79 * kilometers;
        return taxiPrice;
    }
    else if (travelTime == "night" && (kilometers >= 20 && kilometers < 100))
    {
        taxiPrice = 0.70 + 0.90 * kilometers;
        busPrice = 0.09 * kilometers;
        if (taxiPrice < busPrice)
        {
            return taxiPrice;
        }
        else
        {
            return busPrice;
        }
    }
    else if (travelTime == "night" && kilometers >= 100)
    {
        taxiPrice = 0.70 + 0.90 * kilometers;
        trainPrice = 0.06 * kilometers;
        if (taxiPrice < trainPrice)
        {
            return taxiPrice;
        }
        else
        {
            return trainPrice;
        }
    }
    else
    {
        taxiPrice = 0.70 + 0.90 * kilometers;
        return taxiPrice;
    }
}