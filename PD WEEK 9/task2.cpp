#include <iostream>
using namespace std;
main()
{
    bool found = false;
    int ticketPrice = 500;
    int discount;
    string movieName;
    string movies[5] = {"Gladiator", "Star Wars", "Terminator", "Taking Lives", "Tomb Rider"};
    cout << "Enter Movie Name: ";
    getline(cin, movieName);
    for (int index = 0; index < 5; index++)
    {
        if (movieName == movies[index])
        {
            found = true;
            if (index % 2 == 0)
            {
                discount = ticketPrice * 0.1;
                discount = ticketPrice - discount;
                cout << "Ticket Price: " << discount;
                break;
            }
            else
            {
                discount = ticketPrice * 0.05;
                discount = ticketPrice - discount;
                cout << "Ticket Price: " << discount;
                break;
            }
        }
    }
    if(found == false)
    {
        cout << "Movie Not Found";
    }
}
