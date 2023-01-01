#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
void printName();
main()
{
 gotoxy(0,15);
 printName();
 gotoxy(0,35);
}
void printName() 
{
 cout << "   ##########   ###########   #########      #          #  #           #            ##########   #          #    " << endl;
 cout << "  #          #  #          #  #        #     #          #  #           #           #          #  #          #    " << endl;
 cout << "  #          #  #          #  #         #    #          #  #           #           #          #  #          #    " << endl;
 cout << "  #          #  #          #  #          #   #          #  #           #           #          #  #          #    " << endl;
 cout << "  #          #  #  ########   #           #  #          #  #           #           #          #  ############    " << endl;
 cout << "  ############  #          #  #           #  #          #  #           #           ############  #          #    " << endl;
 cout << "  #          #  #          #  #          #   #          #  #           #           #          #  #          #    " << endl;
 cout << "  #          #  #          #  #         #     #        #   #           #           #          #  #          #    " << endl;
 cout << "  #          #  ###########   #########        ########    ##########  ##########  #          #  #          #    " << endl;
}
void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
 