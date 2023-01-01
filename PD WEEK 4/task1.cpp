#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y);
main()
{
 int x, y; 
 gotoxy(4, 10);
 cout << "MY NAME IS ABDULLAH";
}
void gotoxy(int x, int y)
{
 COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

