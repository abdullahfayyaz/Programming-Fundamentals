#include <iostream>
using namespace std;
string zodiacSign(string month, int date);
main()
{
    int date;
    string month;
    string sign;
    cout << "Enter Date of Birth: ";
    cin >> date;
    cout << "Enter Month of Birth: ";
    cin >> month;
    sign = zodiacSign(month, date);
    cout << sign;
}
string zodiacSign(string month, int date)
{
    string sign;
    if ((month == "March" && date >= 21) || (month == "April" && date <= 19))
    {
        sign = "Aries";
    }
    else if ((month == "April" && date >= 20) || (month == "May" && date <= 20))
    {
        sign = "Taurus";
    }
    else if ((month == "May" && date >= 21) || (month == "June" && date <= 20))
    {
        sign = "Gemini";
    }
    else if ((month == "June" && date >= 21) || (month == "July" && date <= 22))
    {
        sign = "Cancer";
    }
    else if ((month == "July" && date >= 23) || (month == "August" && date <= 22))
    {
        sign = "Leo";
    }
    else if ((month == "August" && date >= 23) || (month == "September" && date <= 22))
    {
        sign = "Virgo";
    }
    else if ((month == "September" && date >= 23) || (month == "October" && date <= 22))
    {
        sign = "Libra";
    }
    else if ((month == "October" && date >= 23) || (month == "November" && date <= 21))
    {
        sign = "Scorpio";
    }
    else if ((month == "November" && date >= 22) || (month == "December" && date <= 21))
    {
        sign = "Sagittarius";
    }
    else if ((month == "December" && date >= 22) || (month == "January" && date <= 19))
    {
        sign = "Capricorn";
    }
    else if ((month == "January" && date >= 20) || (month == "February" && date <= 18))
    {
        sign = "Aquarius";
    }
    else if ((month == "February" && date >= 19) || (month == "March" && date <= 20))
    {
        sign = "Pisces";
    }
    return sign;
}
