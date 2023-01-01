#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
void printA();
void printW();
void printI();
void printS();
main()
{
 gotoxy(0,5);
 printA();
 gotoxy(0,15);
 printW();
 gotoxy(0,25);
 printA();
 gotoxy(0,35);
 printI();
 gotoxy(0,45);
 printS();
}
void printA()
{
 cout << "   ##########    " << endl;
 cout << "  #          #   " << endl;
 cout << "  #          #   " << endl;
 cout << "  #          #   " << endl;
 cout << "  #          #   " << endl;
 cout << "  ############   " << endl;
 cout << "  #          #   " << endl;
 cout << "  #          #   " << endl;
 cout << "  #          #   " << endl;
}
void printW()
{
 cout << "  #           #     " << endl;
 cout << "  #           #     " << endl;
 cout << "  #           #     " << endl;
 cout << "  #           #     " << endl;
 cout << "  #     #     #     " << endl;
 cout << "  #    # #    #     " << endl;
 cout << "  #   #   #   #     " << endl;
 cout << "  #  #     #  #     " << endl;
 cout << "  ##         ##     " << endl;
}
void printI()
{
 cout << "  ###########      " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "       #           " << endl;
 cout << "  ###########      " << endl;
}
void printS(){

    cout << "    ######        " << endl;
    cout << "   #      #       " << endl;
    cout << "   #              " << endl;
    cout << "   #              " << endl;
    cout << "    ######        " << endl;
    cout << "          #       " << endl;
    cout << "          #       " << endl;
    cout << "   #      #       " << endl;
    cout << "    ######        " << endl;
}
void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
 