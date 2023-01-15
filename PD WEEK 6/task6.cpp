#include <iostream>
using namespace std;
float studioStay(string month, int numberOfStay);
float apartmentStay(string month, int numberOfStay);
main()
{
    string month;
    int numberOfStay;
    float studio;
    float apartment;
    cout << "Enter Month: ";
    cin >> month;
    cout << "Enter Number of Stays (0 - 200): ";
    cin >> numberOfStay;
    apartment = apartmentStay(month, numberOfStay);
    cout << "Apartment: " << apartment << " $" << endl;
    studio = studioStay(month, numberOfStay);
    cout << "Studio: " << studio << " $";
}
float studioStay(string month, int numberOfStay)
{
    float studioPrice;
    if (month == "May" || month == "October")
    {
        if (numberOfStay > 7 && numberOfStay <= 14)
        {
            studioPrice = numberOfStay * 50;
            studioPrice = studioPrice - (studioPrice * 5) / 100;
        }
        else if (numberOfStay > 14)
        {
            studioPrice = numberOfStay * 50;
            studioPrice = studioPrice - (studioPrice * 30) / 100;
        }
        else
        {
            studioPrice = numberOfStay * 50;
        }
    }
    else if (month == "June" || month == "September")
    {
        if (numberOfStay > 14)
        {
            studioPrice = numberOfStay * 75.20;
            studioPrice = studioPrice - (studioPrice * 20) / 100;
        }
        else
        {
            studioPrice = numberOfStay * 75.20;
        }
    }
    else if (month == "July" || month == "August")
    {
        studioPrice = numberOfStay * 76;
    }
    return studioPrice;
}
float apartmentStay(string month, int numberOfStay)
{
    float apartmentPrice;
    if (month == "May" || month == "October")
    {
        if (numberOfStay > 14)
        {
            apartmentPrice = numberOfStay * 65;
            apartmentPrice = apartmentPrice - (apartmentPrice * 10) / 100;
        }
        else
        {
            apartmentPrice = numberOfStay * 65;
        }
    }
    else if (month == "June" || month == "September")
    {
        if (numberOfStay > 14)
        {
            apartmentPrice = numberOfStay * 68.70;
            apartmentPrice = apartmentPrice - (apartmentPrice * 10) / 100;
        }
        else
        {
            apartmentPrice = numberOfStay * 68.70;
        }
    }
    else if (month == "July" || month == "August")
    {
        if (numberOfStay > 14)
        {
            apartmentPrice = numberOfStay * 77;
            apartmentPrice = apartmentPrice - (apartmentPrice * 10) / 100;
        }
        else
        {
            apartmentPrice = numberOfStay * 77;
        }
    }
    return apartmentPrice;
}