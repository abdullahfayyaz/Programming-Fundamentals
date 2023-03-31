#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

// Function Prototypes
void printHeader();
void clear();
void subMenu(string subMenu);
void mainSubMenu(string mainSubMenu);
int choice();

// For SignUp and Login
void loginSignup();
bool isValidUsername(string userName);
void signUp(string userName, string password);
void storeUserData();
string getField(string record, int field);
void loadUserData();
void viewUsers();
string login(string userName, string password);

// For Manager
void managerInterface();
void managerMenu();
void addCustomer();
void addNewCustomer(string customerName, string customerId, string customerContact, string customerCity, int customerTotalPerson, string customerRoomType, int stay_days, string date);
bool checkCustomer(string customerId);
int foundCustomer(string customerName, string customerId);
void storeCustomerData();
void loadCustomerData();
void updateCustomer();
void updateMenu();
void updateName(string name, int index);
void updateTotalPerson(int personCount, int index);
void updateRoomType(string roomCategory, int index);
void updateStayDay(int stay, int index);
void searchInterface();
void searchCustomer(int index);
void removeInterface();
void removeCustomer(int index);
void bookedRooms();
void availableRooms();
void roomCategories();
void checkoutInterface();
void checkout(int index);
int checkoutBill(int index);
void viewReviews();
void viewRatings();

// For Customer
void customerInterface();
void customerMenu();
void onlineBooking();
void roomSuggestion(int total_person);
void cancelBooking();
void billHistory();
void changePassword();
void customerReview();
void storeReviews();
void loadReviews();
void customerRating();
void storeRating();
void loadRating();

// Global Variables & Arrays

// For Sign Up Users
const int totalUser = 100;
int userCount = 0;
string userNames[totalUser];
string passwords[totalUser];
string roles[totalUser];

// To Add Customers
const int totalRoom = 200;
int customerCount = 0;
const int totalReview = 200;
int reviewCount = 0;
int ratingCount = 0;
int roomCount = 1;
string customer[totalRoom];
string id[totalRoom];
string contact[totalRoom];
string city[totalRoom];
int totalPerson[totalRoom];
string roomType[totalRoom];
int roomNumber[totalRoom];
int no_of_stay[totalRoom];
string checkIn[totalRoom];
string review[totalReview];
string rating[totalReview];
bool exit_app = false;

// Room Prices
float type_single = 3000;
float type_double = 5000;
float type_triple = 8000;
float type_twin = 6000;
float type_executive = 15000;
float type_king = 10000;

// Main Function Implementation
main()
{
    bool signUpCheck;
    string userName;
    string password;
    string role;
    int option = 0;
    loadUserData();
    loadCustomerData();
    loadReviews();
    loadRating();
    while (option != 3)
    {
        printHeader();
        loginSignup();
        option = choice();
        if (option == 1)
        {
            printHeader();
            mainSubMenu("SignUp");
            cout << "Enter User Name: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            signUpCheck = isValidUsername(userName);
            if (signUpCheck == true)
            {
                signUp(userName, password);
                storeUserData();
                cout << "Sign Up Successfully" << endl;
            }
            else
            {
                cout << "Already Exist" << endl;
            }
            clear();
            continue;
        }
        else if (option == 2)
        {
            printHeader();
            mainSubMenu("Login");
            cout << "Enter User Name: ";
            cin >> userName;
            cout << "Enter Password: ";
            cin >> password;
            role = login(userName, password);
            if (role == "manager")
            {
                managerInterface();
                if (exit_app == true)
                {
                    break;
                }
            }
            else if (role == "customer")
            {
                customerInterface();
                if (exit_app == true)
                {
                    break;
                }
            }
            else
            {
                cout << "Invalid Credentials" << endl;
                clear();
            }
        }
        else
        {
            cout << "Wrong input\nTry again" << endl;
            clear();
        }
    }
}

// Function Definition
void printHeader()
{
    system("cls");
    cout << " __   __  _______  _______  _______  ___        __   __  _______  __    _  _______  _______  _______  __   __  _______  __    _  _______    _______  __   __  _______  _______  _______  __   __   " << endl;
    cout << "|  | |  ||       ||       ||       ||   |      |  |_|  ||   _   ||  |  | ||   _   ||       ||       ||  |_|  ||       ||  |  | ||       |  |       ||  | |  ||       ||       ||       ||  |_|  |  " << endl;
    cout << "|  |_|  ||   _   ||_     _||    ___||   |      |       ||  |_|  ||   |_| ||  |_|  ||    ___||    ___||       ||    ___||   |_| ||_     _|  |  _____||  |_|  ||  _____||_     _||    ___||       |  " << endl;
    cout << "|       ||  | |  |  |   |  |   |___ |   |      |       ||       ||       ||       ||   | __ |   |___ |       ||   |___ |       |  |   |    | |_____ |       || |_____   |   |  |   |___ |       |  " << endl;
    cout << "|       ||  |_|  |  |   |  |    ___||   |___   |       ||       ||  _    ||       ||   ||  ||    ___||       ||    ___||  _    |  |   |    |_____  ||_     _||_____  |  |   |  |    ___||       |  " << endl;
    cout << "|   _   ||       |  |   |  |   |___ |       |  | ||_|| ||   _   || | |   ||   _   ||   |_| ||   |___ | ||_|| ||   |___ | | |   |  |   |     _____| |  |   |   _____| |  |   |  |   |___ | ||_|| |  " << endl;
    cout << "|__| |__||_______|  |___|  |_______||_______|  |_|   |_||__| |__||_|  |__||__| |__||_______||_______||_|   |_||_______||_|  |__|  |___|    |_______|  |___|  |_______|  |___|  |_______||_|   |_|  " << endl;
    cout << endl;
}
void clear()
{
    cout << "Press any key to continue: ";
    getch();
}
void subMenu(string subMenu)
{
    string message = "Main Menu > " + subMenu;
    cout << message << endl;
    cout << "--------------------------------------------" << endl;
}
void mainSubMenu(string mainSubMenu)
{
    string message = "Login and Sign-Up Menu > " + mainSubMenu;
    cout << message << endl;
    cout << "--------------------------------------------" << endl;
}
int choice()
{
    int option;
    cout << "Enter Your Choice: ";
    cin >> option;
    return option;
}

// SignUp & Login Functionality
void loginSignup()
{
    cout << "Login and Sign-Up Menu >" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Select one of the following options number..." << endl;
    cout << "1- Sign-Up" << endl;
    cout << "2- Login" << endl;
    cout << "3- Exit" << endl;
}
bool isValidUsername(string userName)
{
    bool isNew = true;
    for (int index = 0; index < userCount; index++)
    {
        if (userNames[index] == userName)
        {
            isNew = false;
            break;
        }
    }
    return isNew;
}
void signUp(string userName, string password)
{
    userNames[userCount] = userName;
    passwords[userCount] = password;
    roles[userCount] = "customer";
    userCount++;
}
void storeUserData()
{
    fstream file;
    file.open("userRecord.txt", ios::out);
    for (int index = 0; index < userCount; index++)
    {
        file << userNames[index] << ",";
        file << passwords[index] << ",";
        if (index == 0)
        {
            file << "manager" << endl;
        }
        else
        {
            file << "customer" << endl;
        }
    }
    file.close();
}
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
void loadUserData()
{
    int index = 0;
    string record;
    fstream file;
    file.open("userRecord.txt", ios::in);
    while (getline(file, record))
    {
        userNames[index] = getField(record, 1);
        passwords[index] = getField(record, 2);
        roles[index] = getField(record, 3);
        index = index + 1;
    }
    file.close();
    userCount = index;
}
string login(string userName, string password)
{
    string role = "undefined";
    for (int index = 0; index < userCount; index++)
    {
        if (userNames[index] == userName && passwords[index] == password)
        {
            return roles[index];
            break;
        }
    }
    return role;
}
void viewUsers()
{
    cout << "User Name"
         << "\t"
         << "Password"
         << "\t"
         << "Role" << endl;
    for (int index = 0; index < userCount; index++)
    {
        cout << userNames[index] << "\t\t" << passwords[index] << "\t\t" << roles[index] << endl;
    }
}

// Manager Functionality
void managerInterface()
{
    int option_manager = 0;
    while (true)
    {
        printHeader();
        managerMenu();
        option_manager = choice();
        if (option_manager == 1)
        {
            printHeader();
            subMenu("Add Customer");
            addCustomer();
            clear();
        }
        else if (option_manager == 2)
        {
            printHeader();
            subMenu("Update Customer");
            updateCustomer();
            clear();
        }
        else if (option_manager == 3)
        {
            printHeader();
            subMenu("Search Customer");
            searchInterface();
            clear();
        }
        else if (option_manager == 4)
        {
            printHeader();
            subMenu("Remove Customer");
            removeInterface();
            clear();
        }
        else if (option_manager == 5)
        {
            printHeader();
            subMenu("View Booked Rooms");
            bookedRooms();
            clear();
        }
        else if (option_manager == 6)
        {
            printHeader();
            subMenu("View Available Rooms");
            availableRooms();
            clear();
        }
        else if (option_manager == 7)
        {
            printHeader();
            subMenu("View Room Categories");
            roomCategories();
            clear();
        }
        else if (option_manager == 8)
        {
            printHeader();
            subMenu("Checkout");
            checkoutInterface();
            clear();
        }
        else if (option_manager == 9)
        {
            printHeader();
            subMenu("View Reviews");
            viewReviews();
            clear();
        }
        else if (option_manager == 10)
        {
            printHeader();
            subMenu("View Ratings");
            viewRatings();
            clear();
        }
        else if (option_manager == 11)
        {
            break;
        }
        else if (option_manager == 12)
        {
            exit_app = true;
            break;
        }
        else
        {
            cout << "Wrong input\nTry again " << endl;
            clear();
        }
    }
}
void managerMenu()
{
    cout << "Main Menu >" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Select one of the following options number..." << endl;
    cout << "1- Add Customer" << endl;
    cout << "2- Update Customer" << endl;
    cout << "3- Search Customer" << endl;
    cout << "4- Remove Customer" << endl;
    cout << "5- View Booked Rooms" << endl;
    cout << "6- View Available Rooms" << endl;
    cout << "7- View Room Categories" << endl;
    cout << "8- Checkout" << endl;
    cout << "9- View Reviews" << endl;
    cout << "10- View Ratings" << endl;
    cout << "11- Logout" << endl;
    cout << "12- Exit" << endl;
}
void addCustomer()
{
    bool isCheck;
    string customerName;
    string customerId;
    string customerContact;
    string customerCity;
    string customerRoomType;
    int customerTotalPerson;
    int stay_days;
    string date;
    if (customerCount < totalRoom)
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter CNIC: ";
        cin >> customerId;
        isCheck = checkCustomer(customerId);
        if (isCheck == true)
        {
            cout << "Enter Contact: ";
            cin >> customerContact;
            cout << "Enter City: ";
            cin >> customerCity;
            cout << "Enter Number of Person: ";
            cin >> customerTotalPerson;
            roomSuggestion(customerTotalPerson);
            cout << "Enter Room Type: ";
            cin >> customerRoomType;
            cout << "Enter No. of Stay: ";
            cin >> stay_days;
            cout << "Enter CheckIn Date: ";
            cin >> date;
            addNewCustomer(customerName, customerId, customerContact, customerCity, customerTotalPerson, customerRoomType, stay_days, date);
            storeCustomerData();
            cout << "Customer Added" << endl;
        }
        else if (isCheck == false)
        {
            cout << "Already Exist" << endl;
        }
    }
    else
    {
        cout << "No Free Room" << endl;
    }
}
bool checkCustomer(string customerId)
{
    bool isNew = true;
    for (int index = 0; index < customerCount; index++)
    {
        if (id[index] == customerId)
        {
            isNew = false;
            break;
        }
    }
    return isNew;
}
int foundCustomer(string customerName, string customerId)
{
    int indexFound = -1;
    for (int index = 0; index < customerCount; index++)
    {
        if (customer[index] == customerName && id[index] == customerId)
        {
            indexFound = index;
            break;
        }
    }
    return indexFound;
}
void addNewCustomer(string customerName, string customerId, string customerContact, string customerCity, int customerTotalPerson, string customerRoomType, int stay_days, string date)
{
    customer[customerCount] = customerName;
    id[customerCount] = customerId;
    contact[customerCount] = customerContact;
    city[customerCount] = customerCity;
    totalPerson[customerCount] = customerTotalPerson;
    roomType[customerCount] = customerRoomType;
    no_of_stay[customerCount] = stay_days;
    checkIn[customerCount] = date;
    roomNumber[customerCount] = roomCount;
    roomCount++;
    customerCount++;
}
void storeCustomerData()
{
    fstream file;
    file.open("customerRecord.txt", ios::out);
    for (int index = 0; index < customerCount; index++)
    {
        file << customer[index] << ",";
        file << id[index] << ",";
        file << contact[index] << ",";
        file << city[index] << ",";
        file << totalPerson[index] << ",";
        file << roomType[index] << ",";
        file << no_of_stay[index] << ",";
        file << checkIn[index] << ",";
        file << roomNumber[index] << endl;
    }
    file.close();
}
void loadCustomerData()
{
    int index = 0;
    string record;
    fstream file;
    file.open("customerRecord.txt", ios::in);
    while (getline(file, record))
    {
        customer[index] = getField(record, 1);
        id[index] = getField(record, 2);
        contact[index] = getField(record, 3);
        city[index] = getField(record, 4);
        totalPerson[index] = stoi(getField(record, 5));
        roomType[index] = getField(record, 6);
        no_of_stay[index] = stoi(getField(record, 7));
        checkIn[index] = getField(record, 8);
        roomNumber[index] = stoi(getField(record, 9));
        index = index + 1;
    }
    file.close();
    customerCount = index;
    roomCount = index + 1;
}
void updateCustomer()
{
    int isFound;
    int option_update = 0;
    string customerName;
    string customerId;
    string customerRoomType;
    int stay_days;
    int customerTotalPerson;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "Customer Not Found" << endl;
    }
    else
    {
        while (true)
        {
            printHeader();
            subMenu("Update Customer");
            updateMenu();
            option_update = choice();
            if (option_update == 1)
            {
                cout << "Enter Customer Name: ";
                cin >> customerName;
                updateName(customerName, isFound);
                continue;
            }
            else if (option_update == 2)
            {
                cout << "Enter Number of Person: ";
                cin >> customerTotalPerson;
                updateTotalPerson(customerTotalPerson, isFound);
                continue;
            }
            else if (option_update == 3)
            {
                cout << "Enter Room Type: ";
                cin >> customerRoomType;
                updateRoomType(customerRoomType, isFound);
                continue;
            }
            else if (option_update == 4)
            {
                cout << "Enter No. of Stay: ";
                cin >> stay_days;
                updateStayDay(stay_days, isFound);
                continue;
            }
            else if (option_update == 5)
            {
                storeCustomerData();
                cout << "Successfully Saved" << endl;
                break;
            }
        }
    }
}
void updateMenu()
{
    cout << "Select option to make changes...." << endl;
    cout << "1- Customer Name" << endl;
    cout << "2- Number of Person" << endl;
    cout << "3- Room Type" << endl;
    cout << "4- Number of Stay" << endl;
    cout << "5- Save Changes" << endl;
    cout << endl;
}
void updateName(string name, int index)
{
    customer[index] = name;
}
void updateTotalPerson(int personCount, int index)
{
    totalPerson[index] = personCount;
}
void updateRoomType(string roomCategory, int index)
{
    roomType[index] = roomCategory;
}
void updateStayDay(int stay, int index)
{
    no_of_stay[index] = stay;
}
void searchInterface()
{
    int isFound;
    string customerName;
    string customerId;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "Customer is not staying in this hotel" << endl;
    }
    else
    {
        searchCustomer(isFound);
    }
}
void searchCustomer(int index)
{
    printHeader();
    subMenu("Search Customer");
    cout << "Customer Name: " << customer[index] << endl;
    cout << "Room Number: " << roomNumber[index] << endl;
    cout << "Room Type: " << roomType[index] << endl;
    cout << "Number of Person: " << totalPerson[index] << endl;
    cout << "No. of Stay: " << no_of_stay[index] << endl;
    cout << "CNIC: " << id[index] << endl;
    cout << "City: " << city[index] << endl;
    cout << "Contact: " << contact[index] << endl;
    cout << "CheckIn Date: " << checkIn[index] << endl;
}
void removeInterface()
{
    int isFound;
    string customerName;
    string customerId;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "Customer Not Found" << endl;
    }
    else
    {
        removeCustomer(isFound);
        storeCustomerData();
        cout << "Customer Removed" << endl;
    }
}
void removeCustomer(int index)
{
    customer[index] = " ";
    for (int x = 0; x < customerCount; x++)
    {
        if (customer[x] == " ")
        {
            customer[x] = customer[x + 1];
            id[x] = id[x + 1];
            contact[x] = contact[x + 1];
            city[x] = city[x + 1];
            totalPerson[x] = totalPerson[x + 1];
            roomType[x] = roomType[x + 1];
            roomNumber[x] = roomNumber[x + 1];
            no_of_stay[x] = no_of_stay[x + 1];
            checkIn[x] = checkIn[x + 1];
            customer[x + 1] = " ";
        }
    }
    customerCount--;
}
void bookedRooms()
{
    cout << "Customer Name"
         << "\t\t\t"
         << "Room Number"
         << "\t"
         << "No. of Person"
         << "\t"
         << "No. of Stay"
         << "\t"
         << "Contact"
         << "\t\t"
         << "CheckIn Date"
         << "\t"
         << "Room Type"
         << endl;
    for (int index = 0; index < customerCount; index++)
    {
        cout << customer[index] << "\t\t\t\t" << roomNumber[index] << "\t\t" << totalPerson[index] << "\t\t" << no_of_stay[index] << "\t\t" << contact[index] << "\t" << checkIn[index] << "\t" << roomType[index] << endl;
    }
}
void availableRooms()
{
    int freeRooms;
    freeRooms = totalRoom - customerCount;
    cout << "Total Rooms: " << totalRoom << endl;
    cout << "No. of Available Rooms: " << freeRooms << endl;
}
void roomCategories()
{
    cout << "\t"
         << "Room Categories & their Facilities" << endl;
    cout << endl;
    cout << "1- Single: A room assigned to one person that consist of single bed." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_single << endl;
    cout << endl;
    cout << "2- Double: A room assigned to two people. May have one or more beds." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_double << endl;
    cout << endl;
    cout << "3- Triple: A room that can accommodate three persons and has been fitted with three twin beds." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_triple << endl;
    cout << endl;
    cout << "4- Twin: A room with two twin beds. May be occupied by one or more people." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_twin << endl;
    cout << endl;
    cout << "5- Executive: A parlour or living room connected with to one or more bedrooms." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_executive << endl;
    cout << endl;
    cout << "6- King: A room with a king-sized bed. May be occupied by one or more people." << endl;
    cout << "\t"
         << "* Price Per Night: " << type_king << endl;
    cout << endl;
}
void checkoutInterface()
{
    int isFound;
    float bill = 0;
    string customerName;
    string customerId;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "Customer is not staying in this hotel" << endl;
    }
    else
    {
        printHeader();
        subMenu("Checkout");
        checkout(isFound);
        removeCustomer(isFound);
        storeCustomerData();
        cout << "Thank You!" << endl;
    }
}
void checkout(int index)
{
    cout << "Customer Name: " << customer[index] << endl;
    cout << "Room Number: " << roomNumber[index] << endl;
    cout << "Room Type: " << roomType[index] << endl;
    cout << "Number of Person: " << totalPerson[index] << endl;
    cout << "No. of Stay: " << no_of_stay[index] << endl;
    cout << "CNIC: " << id[index] << endl;
    cout << "City: " << city[index] << endl;
    cout << "Contact: " << contact[index] << endl;
    cout << "CheckIn Date: " << checkIn[index] << endl;
    cout << "Total Bill: " << checkoutBill(index) << endl;
}
int checkoutBill(int index)
{
    int bill = 0;
    if (roomType[index] == "single" || roomType[index] == "Single")
    {
        bill = type_single * no_of_stay[index];
    }
    else if (roomType[index] == "double" || roomType[index] == "Double")
    {
        bill = type_double * no_of_stay[index];
    }
    else if (roomType[index] == "triple" || roomType[index] == "Triple")
    {
        bill = type_triple * no_of_stay[index];
    }
    else if (roomType[index] == "twin" || roomType[index] == "Twin")
    {
        bill = type_twin * no_of_stay[index];
    }
    else if (roomType[index] == "executive" || roomType[index] == "Executive")
    {
        bill = type_executive * no_of_stay[index];
    }
    else if (roomType[index] == "king" || roomType[index] == "King")
    {
        bill = type_king * no_of_stay[index];
    }
    return bill;
}
void viewReviews()
{
    for (int index = 0; index < reviewCount; index++)
    {
        cout << "> " << review[index] << endl;
    }
}
void viewRatings()
{
    for (int index = 0; index < ratingCount; index++)
    {
        cout << "> " << rating[index] << endl;
    }
}

// Customer Functionality
void customerInterface()
{
    int option_customer = 0;
    while (true)
    {
        printHeader();
        customerMenu();
        option_customer = choice();
        if (option_customer == 1)
        {
            printHeader();
            subMenu("View Room Categories");
            roomCategories();
            clear();
        }
        else if (option_customer == 2)
        {
            printHeader();
            subMenu("Online Booking");
            onlineBooking();
            clear();
        }
        else if (option_customer == 3)
        {
            printHeader();
            subMenu("Cancel Booking");
            cancelBooking();
            clear();
        }
        else if (option_customer == 4)
        {
            printHeader();
            subMenu("Billing History");
            billHistory();
            clear();
        }
        else if (option_customer == 5)
        {
            printHeader();
            subMenu("Change Password");
            changePassword();
        }
        else if (option_customer == 6)
        {
            printHeader();
            subMenu("Give Reviews");
            customerReview();
            clear();
        }
        else if (option_customer == 7)
        {
            printHeader();
            subMenu("Give Ratings");
            customerRating();
            clear();
        }
        else if (option_customer == 8)
        {
            break;
        }
        else if (option_customer == 9)
        {
            exit_app = true;
            break;
        }
        else
        {
            cout << "Wrong input\nTry again " << endl;
            clear();
        }
    }
}
void customerMenu()
{
    cout << "Main Menu >" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Select one of the following options number..." << endl;
    cout << "1- View Room Categories" << endl;
    cout << "2- Online Booking" << endl;
    cout << "3- Cancel Booking" << endl;
    cout << "4- Billing History" << endl;
    cout << "5- Change Password" << endl;
    cout << "6- Give Reviews" << endl;
    cout << "7- Give Ratings" << endl;
    cout << "8- Logout" << endl;
    cout << "9- Exit" << endl;
}
void onlineBooking()
{
    bool isCheck;
    string customerName;
    string customerId;
    string customerContact;
    string customerCity;
    string customerRoomType;
    int customerTotalPerson;
    int stay_days;
    string date;
    if (customerCount < totalRoom)
    {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, customerName);
        cout << "Enter CNIC: ";
        cin >> customerId;
        isCheck = checkCustomer(customerId);
        if (isCheck == true)
        {
            cout << "Enter Contact: ";
            cin >> customerContact;
            cout << "Enter City: ";
            cin >> customerCity;
            cout << "Enter Number of Person: ";
            cin >> customerTotalPerson;
            roomSuggestion(customerTotalPerson);
            cout << "Enter Room Type: ";
            cin >> customerRoomType;
            cout << "Enter No. of Stay: ";
            cin >> stay_days;
            cout << "Enter CheckIn Date: ";
            cin >> date;
            addNewCustomer(customerName, customerId, customerContact, customerCity, customerTotalPerson, customerRoomType, stay_days, date);
            storeCustomerData();
            cout << "Customer Added" << endl;
        }
        else if (isCheck == false)
        {
            cout << "Already Exist" << endl;
        }
    }
    else
    {
        cout << "No Free Room" << endl;
    }
}
void roomSuggestion(int total_person)
{
    if (total_person == 1)
    {
        cout << "---------------------" << endl;
        cout << "Recommended Room Type" << endl;
        cout << "> Single" << endl;
        cout << "> Twin" << endl;
        cout << "> King" << endl;
        cout << "---------------------" << endl;
    }
    else if (total_person == 2)
    {
        cout << "---------------------" << endl;
        cout << "Recommended Room Type" << endl;
        cout << "> Double" << endl;
        cout << "> Twin" << endl;
        cout << "> King" << endl;
        cout << "> Executive" << endl;
        cout << "---------------------" << endl;
    }
    else if (total_person == 3)
    {
        cout << "---------------------" << endl;
        cout << "Recommended Room Type" << endl;
        cout << "> Triple" << endl;
        cout << "> King" << endl;
        cout << "> Executive" << endl;
        cout << "---------------------" << endl;
    }
    else
    {
        cout << "---------------------" << endl;
        cout << "Recommended Room Type" << endl;
        cout << "> King" << endl;
        cout << "> Executive" << endl;
        cout << "---------------------" << endl;
    }
}
void cancelBooking()
{
    int isFound;
    string customerName;
    string customerId;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "Not Booked" << endl;
    }
    else
    {
        removeCustomer(isFound);
        storeCustomerData();
        cout << "Booking Canceled" << endl;
    }
}
void billHistory()
{
    int isFound;
    string customerName;
    string customerId;
    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter Customer CNIC: ";
    cin >> customerId;
    isFound = foundCustomer(customerName, customerId);
    if (isFound == -1)
    {
        cout << "No Record Found" << endl;
    }
    else
    {
        checkout(isFound);
    }
}
void changePassword()
{
    bool isFound = false;
    bool exit = false;
    string password;
    string newPassword1;
    string newPassword2;
    char back;
    while (true)
    {
        printHeader();
        subMenu("Change Password");
        cout << "Enter Old Password: ";
        cin >> password;
        for (int index = 0; index < userCount; index++)
        {
            if (passwords[index] == password)
            {
                isFound = true;
                cout << "Enter New Password: ";
                cin >> newPassword1;
                if (newPassword1 == password)
                {
                    cout << "Same as old password" << endl;
                    cout << "Try Again" << endl;
                    cout << "Enter (y) to continue or (n) for back: ";
                    cin >> back;
                    if (back == 'y')
                    {
                        break;
                    }
                    else if (back == 'n')
                    {
                        exit = true;
                        break;
                    }
                }
                else if (newPassword1 != password)
                {
                    cout << "Confirm New Password: ";
                    cin >> newPassword2;
                }
                if (newPassword2 == newPassword1)
                {
                    passwords[index] = newPassword2;
                    cout << "Password Changed" << endl;
                    storeUserData();
                    exit = true;
                    clear();
                    break;
                }
                else if (newPassword2 != newPassword1)
                {
                    cout << "Password Not Match" << endl;
                    cout << "Try Again" << endl;
                    cout << "Enter (y) to continue or (n) for back: ";
                    cin >> back;
                    if (back == 'y')
                    {
                        break;
                    }
                    else if (back == 'n')
                    {
                        exit = true;
                        break;
                    }
                }
            }
        }
        if (exit == true)
        {
            break;
        }
        else if (isFound == false)
        {
            cout << "Password Not Match" << endl;
            cout << "Try Again" << endl;
            cout << "Enter (y) to continue or (n) for back: ";
            cin >> back;
            if (back == 'y')
            {
                continue;
            }
            else if (back == 'n')
            {
                break;
            }
        }
    }
}
void customerReview()
{
    if (reviewCount < totalReview)
    {
        cout << "Enter Review: ";
        cin.ignore();
        getline(cin, review[reviewCount]);
        storeReviews();
        reviewCount++;
    }
}
void storeReviews()
{
    fstream file;
    file.open("reviews.txt", ios::app);
    file << review[reviewCount] << endl;
    file.close();
}
void loadReviews()
{
    int index = 0;
    string record;
    fstream file;
    file.open("reviews.txt", ios::in);
    while (!file.eof())
    {
        getline(file, record);
        review[index] = record;
        index = index + 1;
    }
    file.close();
    reviewCount = index;
}
void customerRating()
{
    if (ratingCount < totalReview)
    {
        cout << "Give Rating (1.5 - 4.5): ";
        cin >> rating[ratingCount];
        storeRating();
        ratingCount++;
    }
}
void storeRating()
{
    fstream file;
    file.open("rating.txt", ios::app);
    file << rating[ratingCount] << endl;
    file.close();
}
void loadRating()
{
    int index = 0;
    string record;
    fstream file;
    file.open("rating.txt", ios::in);
    while (!file.eof())
    {
        getline(file, record);
        rating[index] = record;
        index = index + 1;
    }
    file.close();
    ratingCount = index;
}