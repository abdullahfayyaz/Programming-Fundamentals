#include <iostream>
using namespace std;
float budget(float totalBudget, string category, int people);
main()
{
    system("cls");
    string category;
    float budgetAmount;
    float totalBudget;
    int people;
    float moneyLeft;
    float needMoney;
    float totalTickets;
    cout << "Enter Budget (1000.00 - 1000 000.00): ";
    cin >> totalBudget;
    cout << "Enter Category (VIP = 499.99 QR or NORMAL =249.99 QR): ";
    cin >> category;
    cout << "Enter Number of People (1 - 200): ";
    cin >> people;
    budgetAmount = budget(totalBudget, category, people);
    if (category == "vip")
    {
        totalTickets = people * 499.99;
        if (totalTickets < budgetAmount)
        {
            moneyLeft = budgetAmount - totalTickets;
            cout << "Yes! You have " << moneyLeft << " QR left.";
        }
        else
        {
            needMoney = totalTickets - budgetAmount;
            cout << "Not enough money! You need " << needMoney << " QR.";
        }
    }
    else if (category == "normal")
    {
        totalTickets = people * 249.99;
        if (totalTickets < budgetAmount)
        {
            moneyLeft = budgetAmount - totalTickets;
            cout << "Yes! You have " << moneyLeft << " QR left.";
        }
        else
        {
            needMoney = totalTickets - budgetAmount;
            cout << "Not enough money! You need " << needMoney << " QR.";
        }
    }
}
float budget(float totalBudget, string category, int people)
{
    float transportBudget;
    float remainingBudget;
    if (people >= 1 && people <= 4)
    {
        transportBudget = totalBudget * 75.0 / 100;
        remainingBudget = totalBudget - transportBudget;
    }
    else if (people >= 5 && people <= 9)
    {
        transportBudget = totalBudget * 60.0 / 100;
        remainingBudget = totalBudget - transportBudget;
    }
    else if (people >= 10 && people <= 24)
    {
        transportBudget = totalBudget * 50.0 / 100;
        remainingBudget = totalBudget - transportBudget;
    }
    else if (people >= 25 && people <= 49)
    {
        transportBudget = totalBudget * 40.0 / 100;
        remainingBudget = totalBudget - transportBudget;
    }
    else
    {
        transportBudget = totalBudget * 25.0 / 100;
        remainingBudget = totalBudget - transportBudget;
    }
    return remainingBudget;
}