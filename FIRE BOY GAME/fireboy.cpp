#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

// Function Prototypes
void gameTitle();
void gameLogo();
void generateColors();
void printHead();
void loading();
void menu();
void subMenu(string subMenu);
int choice();
void clear();
void options();
void keys();
void instructions();
bool gameOverCheck();
void displayWinner();
void displayLoser();
void maze();
void printMaze(char maze[][104]);
void printKey(int x, int y);
void eraseKey(int x, int y);
void fallKey();
void pickKey();
void displayPickKey();
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void eraseFireboy();
void printFireboy();
void restartFireBoy();
void fireBoyRight();
void fireBoyLeft();
void fireBoyUp();
void fireBoyDown();
void fireBoyJump();
void playerHealth();
void generatePlayerBullet();
void movePlayerBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);
void bulletCollisionWithEnemy();
void Enemy1BulletCollisionWithPlayer();
void Enemy2BulletCollisionWithPlayer();
void Enemy3BulletCollisionWithPlayer();
void generateEnemy1Bullet();
void moveEnemy1Bullet();
void makeBulletInactiveE1(int index);
void printEnemy1Bullet(int x, int y);
void eraseEnemy1Bullet(int x, int y);
void generateEnemy2Bullet();
void moveEnemy2Bullet();
void makeBulletInactiveE2(int index);
void printEnemy2Bullet(int x, int y);
void eraseEnemy2Bullet(int x, int y);
void generateEnemy3Bullet();
void moveEnemy3Bullet();
void makeBulletInactiveE3(int index);
void printEnemy3Bullet(int x, int y);
void eraseEnemy3Bullet(int x, int y);
void addScore();
void printScore();
void printEnemy1();
void eraseEnemy1();
void moveEnemy1();
void enemy1_health();
void removeEnemy1();
void printEnemy2();
void eraseEnemy2();
void moveEnemy2();
void enemy2_health();
void removeEnemy2();
void printEnemy3();
void eraseEnemy3();
void moveEnemy3();
void enemy3Left();
void enemy3Right();
void enemy3Up();
void enemy3Down();
void freeEnemy2();
void enemy3_health();
void removeEnemy3();
void freeEnemy3();
void openDoor(char maze[][104]);
bool winner();
void saveGame();
string getField(string record, int field);
void loadGame();
void loadMenu();
void storePresence(int check1, int check2, int check3);

// Global Variables and Arrays

// FireBoy Character

int fireBoyX = 3;  // X Coordinate of FireBoy
int fireBoyY = 40; // Y Coordinate of FireBoy
char leftHand = 47;
char body = 219;
char rightHand = 92;
char legs = 227;
char fireboy[3][3] = {{' ', 2, ' '},
                      {leftHand, body, rightHand},
                      {' ', legs, ' '}};
int fireBoyHealth = 200;
int healthCount = 3;

// Enemy 1(icy) Character

int enemy1X = 95; // X Coordinate of Enemy 1
int enemy1Y = 30; // Y Coordinate of Enemy 1
bool stopEnemy = false;
bool enemy1Present = true;
string enemyDirection1 = "left";
char icy[3][6] = {{' ', ' ', ' ', '-', '-', '-'},
                  {'<', '=', '=', '(', '-', ')'},
                  {' ', ' ', ' ', '*', '*', '*'}};

// Enemy 2(watery) Character

int enemy2X = 98; // X Coordinate of Enemy 2
int enemy2Y = 13; // Y Coordinate of Enemy 2
bool enemy2Present = true;
bool stopEnemy2 = true;
bool isEnemy2Free = false;
int enemy2Speed = 0;
string enemyDirection2 = "down";
char eyes = 233;
char eyebrows = 123;
char box = 219;
char watery[5][3] = {{' ', ' ', 30},
                     {' ', eyebrows, eyes},
                     {29, ' ', box},
                     {' ', eyebrows, eyes},
                     {' ', ' ', 31}};

// Enemy 3(airy) Character

int enemy3X = 97; // X Coordinate of Enemy 3
int enemy3Y = 1;  // Y Coordinate of Enemy 3
int moveRandom = 0;
int enemy3Speed = 0;
bool enemy3Present = true;
bool stopEnemy3 = true;
bool isEnemy3Free = false;
string enemyDirection3 = "down";
char box2 = 219;
char airy[3][5] = {{' ', ' ', 21, ' ', ' '},
                   {29, box2, box2, box2, 16},
                   {' ', ' ', 21, ' ', ' '}};

// Key
char k1 = 23;
char k2 = 248;
char key[2][1] = {{k1},
                  {k2}};

// Bullets

int bulletX[10000]; // Player
int bulletY[10000];
bool isBulletActive[10000];
int bulletCount = 0;

int bulletEnemy1X[10000]; // Enemy 1
int bulletEnemy1Y[10000];
bool isBulletEnemy1Active[10000];
int bulletEnemy1Count = 0;
int enemy1Shot = 0;

int bulletEnemy2X[10000]; // Enemy 2
int bulletEnemy2Y[10000];
bool isBulletEnemy2Active[10000];
int bulletEnemy2Count = 0;
int enemy2Shot = 0;

int bulletEnemy3X[10000]; // Enemy 2
int bulletEnemy3Y[10000];
bool isBulletEnemy3Active[10000];
int bulletEnemy3Count = 0;
int enemy3Shot = 0;

// Score

int score = 0;

// Health

int enemy1Health = 200;
int enemy2Health = 200;
int enemy3Health = 200;

// Keys

int keyX = 0;
int keyY = 0;
int keyCount = 1;

// Door

bool isDoorOpen = false;
bool diamondCollect = false;

// Main Function Implementation
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{
    int option_main = 0;
    system("cls");
    gameTitle();
    loading();
    gameLogo();
    while (true)
    {
        printHead();
        menu();
        option_main = choice();
        if (option_main == 1)
        {
            int opt = 0;
            printHead();
            loadMenu();
            opt = choice();
            if (opt == 2)
            {
                loadGame();
            }
            bool gameRunning = true;
            bool gameOver = false;
            bool isWinner = false;
            system("cls");
            maze();
            printFireboy();
            if (enemy1Present == true)
            {
                printEnemy1();
            }
            if (enemy2Present == true)
            {
                printEnemy2();
            }
            // if (enemy3Present == true)
            // {
            //     printEnemy3();
            // }
            printScore();
            displayPickKey();
            playerHealth();
            enemy1_health();
            enemy2_health();
            // enemy3_health();
            while (gameRunning)
            {
                fireBoyDown();
                if (GetAsyncKeyState(VK_LEFT))
                {
                    fireBoyLeft();
                }
                if (GetAsyncKeyState(VK_RIGHT))
                {
                    fireBoyRight();
                }
                if (GetAsyncKeyState(VK_UP))
                {
                    fireBoyJump();
                }
                if (GetAsyncKeyState(VK_SPACE))
                {
                    generatePlayerBullet();
                }
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    saveGame();
                    gameRunning = false;
                }
                if (gameOver == true)
                {
                    Sleep(400);
                    system("cls");
                    gameTitle();
                    displayLoser();
                    Sleep(3000);
                    gameRunning = false;
                }
                if (enemy1Present == true)
                {
                    if (stopEnemy == false)
                    {
                        moveEnemy1();
                    }
                    generateEnemy1Bullet();
                }
                if (isEnemy2Free == true)
                {
                    freeEnemy2();
                    isEnemy2Free = false;
                }
                if (enemy2Present == true)
                {
                    if (stopEnemy2 == false)
                    {
                        moveEnemy2();
                        generateEnemy2Bullet();
                    }
                }
                if (enemy3Present == true)
                {
                    if (stopEnemy3 == false)
                    {
                        moveEnemy3();
                        generateEnemy3Bullet();
                    }
                }
                if (isDoorOpen == true)
                {
                    maze();
                }
                if (isWinner == true)
                {
                    Sleep(400);
                    system("cls");
                    gameTitle();
                    displayWinner();
                    Sleep(3000);
                    gameRunning = false;
                }
                movePlayerBullet();
                moveEnemy1Bullet();
                moveEnemy2Bullet();
                moveEnemy3Bullet();
                bulletCollisionWithEnemy();
                Enemy1BulletCollisionWithPlayer();
                Enemy2BulletCollisionWithPlayer();
                Enemy3BulletCollisionWithPlayer();
                restartFireBoy();
                gameOver = gameOverCheck();
                isWinner = winner();
                Sleep(50);
                fallKey();
            }
        }
        else if (option_main == 2)
        {
            int game_option = 0;
            while (true)
            {
                printHead();
                options();
                game_option = choice();
                if (game_option == 1)
                {
                    printHead();
                    subMenu("Keys");
                    keys();
                    clear();
                }
                else if (game_option == 2)
                {
                    printHead();
                    subMenu("Instructions");
                    instructions();
                    clear();
                }
                else if (game_option == 3)
                {
                    break;
                }
            }
        }
        else if (option_main == 3)
        {
            system("cls");
            return 0;
        }
    }
}

// Function Definition
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
void printHead()
{
    system("cls");
    gameTitle();
    gameLogo();
}
void loading()
{
    SetConsoleTextAttribute(hConsole, 14);
    char bar1 = 176;
    char bar2 = 219;
    gotoxy(50, 20);
    SetConsoleTextAttribute(hConsole, 12);
    cout << " (        )         (     (        )          " << endl;
    gotoxy(50, 21);
    cout << " )\\ )  ( /(   (     )\\ )  )\\ )  ( /(  (       " << endl;
    gotoxy(50, 22);
    cout << "(()/(  )\\())  )\\   (()/( (()/(  )\\()) )\\ )    " << endl;
    gotoxy(50, 23);
    cout << " /(_))((_)\\((((_)(  /(_)) /(_))((_)\\ (()/(    " << endl;
    gotoxy(50, 24);
    cout << "(_))    ((_))\\ _ )\\(_))_ (_))   _((_) /(_))_  " << endl;
    gotoxy(50, 25);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "| |    / _ \\(_)_\\(_)|   \\|_ _| | \\| |(_)) __| " << endl;
    gotoxy(50, 26);
    cout << "| |__ | (_) |/ _ \\  | |) || |  | .` |  | (_ | " << endl;
    gotoxy(50, 27);
    cout << "|____| \\___//_/ \\_\\ |___/|___| |_|\\_|   \\___| " << endl;
    SetConsoleTextAttribute(hConsole, 15);

    SetConsoleTextAttribute(hConsole, 12);
    for (int i = 0; i < 25; i++)
    {
        gotoxy(61 + i, 29);
        cout << bar1;
    }
    cout << "\r";
    cout << "\t"
         << "\t"
         << "\t";
    for (int i = 0; i < 24; i++)
    {
        gotoxy(61 + i, 29);
        cout << bar2;
        Sleep(150);
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void menu()
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Main Menu" << endl;
    cout << "-------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "1- Start" << endl;
    cout << "2- Option" << endl;
    cout << "3- Exit" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void loadMenu()
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Menu" << endl;
    cout << "-------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "1- Start New Game" << endl;
    cout << "2- Load Game" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void subMenu(string subMenu)
{
    SetConsoleTextAttribute(hConsole, 14);
    string message = subMenu;
    cout << message << endl;
    cout << "-------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
int choice()
{
    SetConsoleTextAttribute(hConsole, 14);
    int option;
    cout << "Enter Your Choice: ";
    cin >> option;
    return option;
    SetConsoleTextAttribute(hConsole, 15);
}
void clear()
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Press any key to continue " << endl;
    getch();
    SetConsoleTextAttribute(hConsole, 15);
}
void options()
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << "Select one of the following option..." << endl;
    cout << "-------------------------------------" << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "1- Keys" << endl;
    cout << "2- Instructions" << endl;
    cout << "3- Back" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void keys()
{
    SetConsoleTextAttribute(hConsole, 12);
    cout << "1. UP         JUMP" << endl;
    cout << "2. LEFT       GO LEFT" << endl;
    cout << "3. RIGHT      GO RIGHT" << endl;
    cout << "4. SPACE      FIRE" << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void instructions()
{
    SetConsoleTextAttribute(hConsole, 12);
    cout << "1- Food Pallet will increase the score." << endl;
    cout << "2- Player bullet hits the enemies will also increase the score." << endl;
    cout << "3- Enemies Bullet decrease the player health." << endl;
    cout << "4- Health Pill will gives a player life." << endl;
    cout << "5- Collect the three keys that will open the door." << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void gameTitle()
{
    SetConsoleTextAttribute(hConsole, 14);
    cout << " FFFFFFFFFFFFFFFFFFFFFFIIIIIIIIIIRRRRRRRRRRRRRRRRR   EEEEEEEEEEEEEEEEEEEEEE     BBBBBBBBBBBBBBBBB        OOOOOOOOO     YYYYYYY       YYYYYYY      " << endl;
    cout << " F::::::::::::::::::::FI::::::::IR::::::::::::::::R  E::::::::::::::::::::E     B::::::::::::::::B     OO:::::::::OO   Y:::::Y       Y:::::Y      " << endl;
    cout << " F::::::::::::::::::::FI::::::::IR::::::RRRRRR:::::R E::::::::::::::::::::E     B::::::BBBBBB:::::B  OO:::::::::::::OO Y:::::Y       Y:::::Y      " << endl;
    cout << " FF::::::FFFFFFFFF::::FII::::::IIRR:::::R     R:::::REE::::::EEEEEEEEE::::E     BB:::::B     B:::::BO:::::::OOO:::::::OY::::::Y     Y::::::Y      " << endl;
    cout << "   F:::::F       FFFFFF  I::::I    R::::R     R:::::R  E:::::E       EEEEEE       B::::B     B:::::BO::::::O   O::::::OYYY:::::Y   Y:::::YYY      " << endl;
    cout << "   F:::::F               I::::I    R::::R     R:::::R  E:::::E                    B::::B     B:::::BO:::::O     O:::::O   Y:::::Y Y:::::Y         " << endl;
    cout << "   F::::::FFFFFFFFFF     I::::I    R::::RRRRRR:::::R   E::::::EEEEEEEEEE          B::::BBBBBB:::::B O:::::O     O:::::O    Y:::::Y:::::Y          " << endl;
    cout << "   F:::::::::::::::F     I::::I    R:::::::::::::RR    E:::::::::::::::E          B:::::::::::::BB  O:::::O     O:::::O     Y:::::::::Y           " << endl;
    cout << "   F:::::::::::::::F     I::::I    R::::RRRRRR:::::R   E:::::::::::::::E          B::::BBBBBB:::::B O:::::O     O:::::O      Y:::::::Y            " << endl;
    cout << "   F::::::FFFFFFFFFF     I::::I    R::::R     R:::::R  E::::::EEEEEEEEEE          B::::B     B:::::BO:::::O     O:::::O       Y:::::Y             " << endl;
    cout << "   F:::::F               I::::I    R::::R     R:::::R  E:::::E                    B::::B     B:::::BO:::::O     O:::::O       Y:::::Y             " << endl;
    cout << "   F:::::F               I::::I    R::::R     R:::::R  E:::::E       EEEEEE       B::::B     B:::::BO::::::O   O::::::O       Y:::::Y             " << endl;
    cout << " FF:::::::FF           II::::::IIRR:::::R     R:::::REE::::::EEEEEEEE:::::E     BB:::::BBBBBB::::::BO:::::::OOO:::::::O       Y:::::Y             " << endl;
    cout << " F::::::::FF           I::::::::IR::::::R     R:::::RE::::::::::::::::::::E     B:::::::::::::::::B  OO:::::::::::::OO     YYYY:::::YYYY          " << endl;
    cout << " F::::::::FF           I::::::::IR::::::R     R:::::RE::::::::::::::::::::E     B::::::::::::::::B     OO:::::::::OO       Y:::::::::::Y          " << endl;
    cout << " FFFFFFFFFFF           IIIIIIIIIIRRRRRRRR     RRRRRRREEEEEEEEEEEEEEEEEEEEEE     BBBBBBBBBBBBBBBBB        OOOOOOOOO         YYYYYYYYYYYYY          " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void displayWinner()
{
    SetConsoleTextAttribute(hConsole, 12);
    gotoxy(40, 20);
    cout << "           (        )     )       (        " << endl;
    gotoxy(40, 21);
    cout << " (  (      )\\ )  ( /(  ( /(       )\\ )     " << endl;
    gotoxy(40, 22);
    cout << " )\\))(   '(()/(  )\\()) )\\()) (   (()/(     " << endl;
    gotoxy(40, 23);
    cout << "((_)()\\ )  /(_))((_)\\ ((_)\\  )\\   /(_))    " << endl;
    gotoxy(40, 24);
    cout << "_(())\\_)()(_))   _((_) _((_)((_) (_))      " << endl;
    gotoxy(40, 25);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\\ \\((_)/ /|_ _| | \\| || \\| || __|| _ \\     " << endl;
    gotoxy(40, 26);
    cout << " \\ \\/\\/ /  | |  | .` || .` || _| |   /     " << endl;
    gotoxy(40, 27);
    cout << "  \\_/\\_/  |___| |_|\\_||_|\\_||___||_|_\\      " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void displayLoser()
{
    SetConsoleTextAttribute(hConsole, 12);
    gotoxy(40, 20);
    cout << "                   *              )               (     " << endl;
    gotoxy(40, 21);
    cout << " (        (      (  `          ( /(               )\\ )  " << endl;
    gotoxy(40, 22);
    cout << " )\\ )     )\\     )\\))(   (     )\\()) (   (   (   (()/(  " << endl;
    gotoxy(40, 23);
    cout << "(()/(  ((((_)(  ((_)()\\  )\\   ((_)\\  )\\  )\\  )\\   /(_)) " << endl;
    gotoxy(40, 24);
    cout << " /(_))_ )\\ _ )\\ (_()((_)((_)    ((_)((_)((_)((_) (_))   " << endl;
    gotoxy(40, 25);
    SetConsoleTextAttribute(hConsole, 14);
    cout << "(_)) __|(_)_\\(_)|  \\/  || __|  / _ \\  \\ / / | __|| _ \\  " << endl;
    gotoxy(40, 26);
    cout << "  | (_ | / _ \\  | |\\/| || _|  | (_) |\\ V /  | _| |   /  " << endl;
    gotoxy(40, 27);
    cout << "   \\___|/_/ \\_\\ |_|  |_||___|  \\___/  \\_/   |___||_|_\\  " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void gameLogo()
{
    SetConsoleTextAttribute(hConsole, 12);
    gotoxy(50, 18);
    cout << "             )                   " << endl;
    gotoxy(50, 19);
    cout << "            ) )     )                    " << endl;
    gotoxy(50, 20);
    cout << "           )   )   ) )               " << endl;
    gotoxy(50, 21);
    cout << "          )   )...)  )         " << endl;
    gotoxy(50, 22);
    cout << "          *          *                                   " << endl;
    gotoxy(50, 23);
    cout << "          *   @   @   *                                   " << endl;
    gotoxy(50, 24);
    cout << "           *         *                                    " << endl;
    gotoxy(50, 25);
    cout << "            *-------*                                           " << endl;
    gotoxy(50, 26);
    cout << "             ||   ||                                               " << endl;
    gotoxy(50, 27);
    cout << "             ||   ||                                                " << endl;
    gotoxy(50, 28);
    cout << "           @/ |___| \\@                                              " << endl;
    gotoxy(50, 29);
    cout << "             /     \\                                 " << endl;
    gotoxy(50, 30);
    cout << "           | |     | |                           " << endl;
    gotoxy(50, 31);
    cout << "           |_|     |_|          " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void maze()
{
    SetConsoleTextAttribute(hConsole, 3);
    char maze[44][104] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', 21, ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', '|', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '|', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};
    if (isDoorOpen == false)
    {
        printMaze(maze);
    }
    else if (isDoorOpen == true)
    {
        openDoor(maze);
    }
}
void printMaze(char maze[][104])
{
    for (int row = 0; row < 44; row++)
    {
        for (int col = 0; col < 104; col++)
        {
            cout << maze[row][col];
        }
        cout << endl;
    }
}
void printKey(int x, int y)
{
    SetConsoleTextAttribute(hConsole, 6);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(x, y + row);
        for (int col = 0; col < 1; col++)
        {
            cout << key[row][col];
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void eraseKey(int x, int y)
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(x, y + row);
        for (int col = 0; col < 1; col++)
        {
            cout << " ";
        }
    }
}
void fallKey()
{
    char next = getCharAtxy(keyX, keyY + 2);
    if (next == ' ')
    {
        eraseKey(keyX, keyY);
        keyY = keyY + 1;
        printKey(keyX, keyY);
    }
}
void saveGame()
{
    fstream file;
    file.open("game.txt", ios::out);
    file << fireBoyX << ",";
    file << fireBoyY << ",";
    file << enemy1X << ",";
    file << enemy1Y << ",";
    file << enemy2X << ",";
    file << enemy2Y << ",";
    file << enemy3X << ",";
    file << enemy3Y << ",";
    file << keyCount << ",";
    file << keyX << ",";
    file << keyY << ",";
    file << fireBoyHealth << ",";
    file << enemy1Health << ",";
    file << enemy2Health << ",";
    file << enemy3Health << ",";
    file << enemy1Present << ",";
    file << enemy2Present << ",";
    file << enemy3Present;
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
void loadGame()
{
    int p1;
    int p2;
    int p3;
    string record;
    fstream data;
    data.open("game.txt", ios::in);
    getline(data, record);
    fireBoyX = stoi(getField(record, 1));
    fireBoyY = stoi(getField(record, 2));
    enemy1X = stoi(getField(record, 3));
    enemy1Y = stoi(getField(record, 4));
    enemy2X = stoi(getField(record, 5));
    enemy2Y = stoi(getField(record, 6));
    enemy3X = stoi(getField(record, 7));
    enemy3Y = stoi(getField(record, 8));
    keyCount = stoi(getField(record, 9));
    keyX = stoi(getField(record, 10));
    keyY = stoi(getField(record, 11));
    fireBoyHealth = stoi(getField(record, 12));
    enemy1Health = stoi(getField(record, 13));
    enemy2Health = stoi(getField(record, 14));
    enemy3Health = stoi(getField(record, 15));
    p1 = stoi(getField(record, 16));
    p2 = stoi(getField(record, 17));
    p3 = stoi(getField(record, 18));
    storePresence(p1, p2, p3);
    data.close();
}
void storePresence(int check1, int check2, int check3)
{
    if (check1 == 1)
    {
        enemy1Present = true;
    }
    else if (check1 == 0)
    {
        enemy1Present = false;
    }
    if (check2 == 1)
    {
        enemy2Present = true;
    }
    else if (check2 == 0)
    {
        enemy2Present = false;
    }
    if (check3 == 1)
    {
        enemy3Present = true;
    }
    else if (check3 == 0)
    {
        enemy3Present = false;
    }
}

// Player Functionality
void printFireboy()
{
    SetConsoleTextAttribute(hConsole, 4);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(fireBoyX, fireBoyY + row);
        for (int col = 0; col < 3; col++)
        {
            cout << fireboy[row][col];
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void eraseFireboy()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(fireBoyX, fireBoyY + row);
        for (int col = 0; col < 3; col++)
        {
            cout << " ";
        }
    }
}
void fireBoyRight()
{
    char nextLocation1 = getCharAtxy(fireBoyX + 3, fireBoyY);
    char nextLocation2 = getCharAtxy(fireBoyX + 3, fireBoyY + 1);
    char nextLocation3 = getCharAtxy(fireBoyX + 3, fireBoyY + 2);
    if ((nextLocation1 == '@' || nextLocation1 == ' ' || (nextLocation1 == k1 || nextLocation1 == k2)) && (nextLocation2 == '@' || nextLocation2 == ' ' || (nextLocation2 == k1 || nextLocation2 == k2)) && (nextLocation3 == '@' || nextLocation3 == ' ' || (nextLocation3 == k1 || nextLocation3 == k2)))
    {
        if (nextLocation1 == '@' || nextLocation2 == '@' || nextLocation3 == '@')
        {
            addScore();
            printScore();
        }
        if ((nextLocation1 == k1 || nextLocation1 == k2) || (nextLocation2 == k1 || nextLocation2 == k2) || (nextLocation3 == k1 || nextLocation3 == k2))
        {
            pickKey();
            displayPickKey();
        }
        eraseFireboy();
        fireBoyX = fireBoyX + 1;
        printFireboy();
    }
}
void fireBoyLeft()
{
    char nextLocation1 = getCharAtxy(fireBoyX - 1, fireBoyY);
    char nextLocation2 = getCharAtxy(fireBoyX - 1, fireBoyY + 1);
    char nextLocation3 = getCharAtxy(fireBoyX - 1, fireBoyY + 2);
    if ((nextLocation1 == '@' || nextLocation1 == ' ' || (nextLocation1 == k1 || nextLocation1 == k2) || nextLocation1 == 21) && (nextLocation2 == '@' || nextLocation2 == ' ' || (nextLocation2 == k1 || nextLocation2 == k2) || nextLocation2 == 21) && (nextLocation3 == '@' || nextLocation3 == ' ' || (nextLocation3 == k1 || nextLocation3 == k2) || nextLocation3 == 21))
    {
        if (nextLocation1 == '@' || nextLocation2 == '@' || nextLocation3 == '@')
        {
            addScore();
            printScore();
        }
        if ((nextLocation1 == k1 || nextLocation1 == k2) || (nextLocation2 == k1 || nextLocation2 == k2) || (nextLocation3 == k1 || nextLocation3 == k2))
        {
            pickKey();
            displayPickKey();
        }
        if (nextLocation1 == 21 || nextLocation2 == 21 || nextLocation3 == 21)
        {
            diamondCollect = true;
        }
        eraseFireboy();
        fireBoyX = fireBoyX - 1;
        printFireboy();
    }
}
void fireBoyDown()
{
    char nextLocation1 = getCharAtxy(fireBoyX, fireBoyY + 3);
    char nextLocation2 = getCharAtxy(fireBoyX + 1, fireBoyY + 3);
    char nextLocation3 = getCharAtxy(fireBoyX + 2, fireBoyY + 3);
    if ((nextLocation1 == '@' || nextLocation1 == ' ' || nextLocation1 == '*') && (nextLocation2 == '@' || nextLocation2 == ' ' || nextLocation2 == '*') && (nextLocation3 == '@' || nextLocation3 == ' ' || nextLocation3 == '*'))
    {
        if (nextLocation1 == '@' || nextLocation2 == '@' || nextLocation3 == '@')
        {
            addScore();
            printScore();
        }
        if (nextLocation1 == '*' || nextLocation2 == '*' || nextLocation3 == '*')
        {
            fireBoyHealth = fireBoyHealth - 10;
        }
        eraseFireboy();
        fireBoyY = fireBoyY + 1;
        printFireboy();
    }
}
void fireBoyJump()
{
    char nextLocation1 = getCharAtxy(fireBoyX, fireBoyY - 2);
    char nextLocation2 = getCharAtxy(fireBoyX + 1, fireBoyY - 2);
    char nextLocation3 = getCharAtxy(fireBoyX + 2, fireBoyY - 2);
    char jump1 = getCharAtxy(fireBoyX, fireBoyY + 3);
    char jump2 = getCharAtxy(fireBoyX + 1, fireBoyY + 3);
    char jump3 = getCharAtxy(fireBoyX + 2, fireBoyY + 3);
    if ((nextLocation1 == '@' || nextLocation1 == ' ' || nextLocation1 == '*' || nextLocation1 == k1) && (nextLocation2 == '@' || nextLocation2 == ' ' || nextLocation2 == '*' || nextLocation2 == k1) && (nextLocation3 == '@' || nextLocation3 == ' ' || nextLocation3 == '*' || nextLocation3 == k1))
    {
        if ((jump1 == '#' || jump1 == '%' || jump1 == '|') && (jump2 == '#' || jump2 == '%' || jump2 == '|') && (jump3 == '#' || jump3 == '%' || jump3 == '|'))
        {
            eraseFireboy();
            fireBoyY = fireBoyY - 6;
            printFireboy();
        }
        if (jump1 == k1 || jump2 == k1 || jump3 == k1)
        {
            eraseFireboy();
            fireBoyY = fireBoyY - 6;
            printFireboy();
        }
        if (nextLocation1 == '@' || nextLocation2 == '@' || nextLocation3 == '@')
        {
            addScore();
            printScore();
        }
        if (nextLocation1 == '*' || nextLocation2 == '*' || nextLocation3 == '*')
        {
            fireBoyHealth = fireBoyHealth - 10;
            playerHealth();
        }
    }
}
void playerHealth()
{

    SetConsoleTextAttribute(hConsole, 12);
    char bar1 = 176;
    char bar2 = 219;
    char heart = 3;
    gotoxy(110, 6);
    cout << "FIRE BOY HEALTH: ";
    if (healthCount == 3)
    {
        gotoxy(128, 6);
        for (int i = 0; i < 3; i++)
        {
            cout << heart << " ";
        }
    }
    else if (healthCount == 2)
    {
        gotoxy(128, 6);
        for (int i = 0; i < 3; i++)
        {
            if (i < 2)
            {
                cout << heart << " ";
            }
            else
            {
                cout << " ";
            }
        }
    }
    else if (healthCount == 1)
    {
        gotoxy(128, 6);
        for (int i = 0; i < 3; i++)
        {
            if (i < 1)
            {
                cout << heart << " ";
            }
            else
            {
                cout << " ";
            }
        }
    }
    gotoxy(135, 6); // Health Bar
    for (int i = 0; i < 20; i++)
    {
        cout << bar1;
    }
    cout << "\r";
    if (fireBoyHealth == 200)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 20; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 190)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 19; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 180)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 18; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 170)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 17; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 160)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 16; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 150)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 15; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 140)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 14; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 130)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 13; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 120)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 12; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 110)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 11; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 100)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 10; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 90)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 9; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 80)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 8; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 70)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 7; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 60)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 6; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 50)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 5; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 40)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 4; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 30)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 3; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 20)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 2; i++)
        {
            cout << bar2;
        }
    }
    else if (fireBoyHealth == 10)
    {
        gotoxy(135, 6);
        for (int i = 0; i < 1; i++)
        {
            cout << bar2;
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void restartFireBoy()
{
    if (fireBoyHealth == 0)
    {
        eraseFireboy();
        fireBoyX = 3;
        fireBoyY = 40;
        printFireboy();
        fireBoyHealth = 200;
        healthCount--;
        playerHealth();
    }
}
bool gameOverCheck()
{
    if (healthCount == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pickKey()
{
    keyCount++;
}
void displayPickKey()
{
    SetConsoleTextAttribute(hConsole, 6);
    int next = 0;
    gotoxy(110, 4);
    cout << "KEYS: ";
    if (keyCount == 1)
    {
        for (int i = 0; i < 1; i++)
        {
            for (int row = 0; row < 2; row++)
            {
                gotoxy(117, 4 + row);
                for (int col = 0; col < 1; col++)
                {
                    cout << key[row][col];
                }
            }
        }
    }
    if (keyCount == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int row = 0; row < 2; row++)
            {
                gotoxy(117 + next, 4 + row);
                for (int col = 0; col < 1; col++)
                {
                    cout << key[row][col];
                }
            }
            next = next + 2;
        }
    }
    if (keyCount == 3)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int row = 0; row < 2; row++)
            {
                gotoxy(117 + next, 4 + row);
                for (int col = 0; col < 1; col++)
                {
                    cout << key[row][col];
                }
            }
            next = next + 2;
        }
        isDoorOpen = true;
    }
    SetConsoleTextAttribute(hConsole, 15);
}

// Bullet Functionality
void generatePlayerBullet()
{
    char next = getCharAtxy(fireBoyX + 3, fireBoyY + 1);
    if (next == ' ')
    {
        bulletX[bulletCount] = fireBoyX + 3;
        bulletY[bulletCount] = fireBoyY + 1;
        isBulletActive[bulletCount] = true;
        gotoxy(fireBoyX + 3, fireBoyY + 1);
        cout << ".";
        bulletCount++;
    }
}
void movePlayerBullet()
{
    SetConsoleTextAttribute(hConsole, 12);
    for (int index = 0; index < bulletCount; index++)
    {
        if (isBulletActive[index] == true)
        {
            char next = getCharAtxy(bulletX[index] + 1, bulletY[index]);
            if (next != ' ')
            {
                eraseBullet(bulletX[index], bulletY[index]);
                makeBulletInactive(index);
            }
            else if (next == ' ')
            {
                eraseBullet(bulletX[index], bulletY[index]);
                bulletX[index] = bulletX[index] + 1;
                printBullet(bulletX[index], bulletY[index]);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void makeBulletInactive(int index)
{

    isBulletActive[index] = false;
}
void bulletCollisionWithEnemy()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (isBulletActive[x] == true)
        {
            if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1 || bulletY[x] == enemy1Y + 2))
            {
                addScore();
                printScore();
                enemy1Health = enemy1Health - 10;
                enemy1_health();
            }
            if (enemy1X - 1 == bulletX[x] && enemy1Y + 1 == bulletY[x])
            {
                addScore();
                printScore();
                enemy1Health = enemy1Health - 10;
                enemy1_health();
            }
            if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1 || bulletY[x] == enemy2Y + 2 || bulletY[x] == enemy2Y + 3 || bulletY[x] == enemy2Y + 4))
            {
                addScore();
                printScore();
                enemy2Health = enemy2Health - 10;
                enemy2_health();
            }
            if (bulletX[x] + 1 == enemy3X && (bulletY[x] == enemy3Y || bulletY[x] == enemy3Y + 1 || bulletY[x] == enemy3Y + 2))
            {
                addScore();
                printScore();
                enemy3Health = enemy3Health - 10;
                enemy3_health();
            }
        }
    }
}
void generateEnemy1Bullet()
{
    char nextLocation = getCharAtxy(enemy1X - 30, enemy1Y + 1);
    if (nextLocation == rightHand)
    {
        if (enemy1Shot % 5 == 0)
        {
            char next = getCharAtxy(enemy1X - 1, enemy1Y + 1);
            if (next == ' ')
            {
                bulletEnemy1X[bulletEnemy1Count] = enemy1X - 1;
                bulletEnemy1Y[bulletEnemy1Count] = enemy1Y + 1;
                isBulletEnemy1Active[bulletEnemy1Count] = true;
                gotoxy(enemy1X - 1, enemy1Y + 1);
                cout << "*";
                bulletEnemy1Count++;
            }
        }
        enemy1Shot++;
        stopEnemy = true;
    }
    else
    {
        stopEnemy = false;
    }
}
void moveEnemy1Bullet()
{
    SetConsoleTextAttribute(hConsole, 5);
    for (int index = 0; index < bulletEnemy1Count; index++)
    {
        if (isBulletEnemy1Active[index] == true)
        {
            char next1 = getCharAtxy(bulletEnemy1X[index] - 1, bulletEnemy1Y[index]);
            char next2 = getCharAtxy(bulletEnemy1X[index], bulletEnemy1Y[index] - 1);
            char next3 = getCharAtxy(bulletEnemy1X[index], bulletEnemy1Y[index] + 1);
            if (next1 != ' ')
            {
                eraseEnemy1Bullet(bulletEnemy1X[index], bulletEnemy1Y[index]);
                makeBulletInactiveE1(index);
            }
            else if (next1 == ' ' || next1 == '.')
            {
                eraseEnemy1Bullet(bulletEnemy1X[index], bulletEnemy1Y[index]);
                bulletEnemy1X[index] = bulletEnemy1X[index] - 1;
                printEnemy1Bullet(bulletEnemy1X[index], bulletEnemy1Y[index]);
            }
            if (next2 != ' ')
            {
                eraseEnemy1Bullet(bulletEnemy1X[index], bulletEnemy1Y[index]);
                makeBulletInactiveE1(index);
            }
            if (next3 != ' ')
            {
                eraseEnemy1Bullet(bulletEnemy1X[index], bulletEnemy1Y[index]);
                makeBulletInactiveE1(index);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void makeBulletInactiveE1(int index)
{

    isBulletEnemy1Active[index] = false;
}
void printEnemy1Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseEnemy1Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateEnemy2Bullet()
{
    if (enemy2Shot % 5 == 0)
    {
        char next = getCharAtxy(enemy2X - 1, enemy2Y + 2);
        if (next == ' ' || next == '.')
        {
            bulletEnemy2X[bulletEnemy2Count] = enemy2X - 1;
            bulletEnemy2Y[bulletEnemy2Count] = enemy2Y + 2;
            isBulletEnemy2Active[bulletEnemy2Count] = true;
            gotoxy(enemy2X - 1, enemy2Y + 2);
            cout << "*";
            bulletEnemy2Count++;
        }
    }
    enemy2Shot++;
}
void moveEnemy2Bullet()
{
    SetConsoleTextAttribute(hConsole, 2);
    for (int index = 0; index < bulletEnemy2Count; index++)
    {
        if (isBulletEnemy2Active[index] == true)
        {
            char next = getCharAtxy(bulletEnemy2X[index] - 1, bulletEnemy2Y[index]);
            if (next != ' ')
            {
                eraseEnemy2Bullet(bulletEnemy2X[index], bulletEnemy2Y[index]);
                makeBulletInactiveE2(index);
            }
            else if (next == ' ' || next == '.')
            {
                eraseEnemy2Bullet(bulletEnemy2X[index], bulletEnemy2Y[index]);
                bulletEnemy2X[index] = bulletEnemy2X[index] - 1;
                printEnemy2Bullet(bulletEnemy2X[index], bulletEnemy2Y[index]);
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void makeBulletInactiveE2(int index)
{

    isBulletEnemy2Active[index] = false;
}
void printEnemy2Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseEnemy2Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void generateEnemy3Bullet()
{
    if (enemy3Shot % 8 == 0)
    {
        char next = getCharAtxy(enemy3X - 2, enemy3Y + 1);
        if (next == ' ' || next == '.')
        {
            bulletEnemy3X[bulletEnemy3Count] = enemy3X - 2;
            bulletEnemy3Y[bulletEnemy3Count] = enemy3Y + 1;
            isBulletEnemy3Active[bulletEnemy3Count] = true;
            gotoxy(enemy3X - 2, enemy3Y + 1);
            cout << "*";
            bulletEnemy3Count++;
        }
    }
    enemy3Shot++;
}
void moveEnemy3Bullet()
{
    for (int index = 0; index < bulletEnemy3Count; index++)
    {
        if (isBulletEnemy3Active[index] == true)
        {
            char next = getCharAtxy(bulletEnemy3X[index] - 1, bulletEnemy3Y[index]);
            if (next != ' ')
            {
                eraseEnemy3Bullet(bulletEnemy3X[index], bulletEnemy3Y[index]);
                makeBulletInactiveE3(index);
            }
            else if (next == ' ' || next == '.')
            {
                eraseEnemy3Bullet(bulletEnemy3X[index], bulletEnemy3Y[index]);
                bulletEnemy3X[index] = bulletEnemy3X[index] - 1;
                printEnemy3Bullet(bulletEnemy3X[index], bulletEnemy3Y[index]);
            }
        }
    }
}
void makeBulletInactiveE3(int index)
{
    isBulletEnemy3Active[index] = false;
}
void printEnemy3Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << "*";
}
void eraseEnemy3Bullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void Enemy1BulletCollisionWithPlayer()
{
    for (int x = 0; x < bulletEnemy1Count; x++)
    {
        if (isBulletEnemy1Active[x] == true)
        {
            if (bulletEnemy1X[x] - 1 == fireBoyX + 1 && bulletEnemy1Y[x] == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] - 1 == fireBoyX + 2 && bulletEnemy1Y[x] == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] - 1 == fireBoyX + 1 && bulletEnemy1Y[x] == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX && bulletEnemy1Y[x] + 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX + 1 && bulletEnemy1Y[x] + 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX + 2 && bulletEnemy1Y[x] + 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX && bulletEnemy1Y[x] - 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX && bulletEnemy1Y[x] - 1 == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy1X[x] == fireBoyX && bulletEnemy1Y[x] - 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
        }
    }
}
void Enemy2BulletCollisionWithPlayer()
{
    for (int x = 0; x < bulletEnemy2Count; x++)
    {
        if (isBulletEnemy2Active[x] == true)
        {
            if (bulletEnemy2X[x] - 1 == fireBoyX + 1 && bulletEnemy2Y[x] == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] - 1 == fireBoyX + 2 && bulletEnemy2Y[x] == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] - 1 == fireBoyX + 1 && bulletEnemy2Y[x] == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] + 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] + 1 == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] + 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] - 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] - 1 == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy2X[x] == fireBoyX && bulletEnemy2Y[x] - 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
        }
    }
}
void Enemy3BulletCollisionWithPlayer()
{
    for (int x = 0; x < bulletEnemy3Count; x++)
    {
        if (isBulletEnemy3Active[x] == true)
        {
            if (bulletEnemy3X[x] - 1 == fireBoyX + 1 && bulletEnemy3Y[x] == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] - 1 == fireBoyX + 2 && bulletEnemy3Y[x] == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] - 1 == fireBoyX + 1 && bulletEnemy3Y[x] == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX && bulletEnemy3Y[x] + 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX + 1 && bulletEnemy3Y[x] + 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX + 2 && bulletEnemy3Y[x] + 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX && bulletEnemy3Y[x] - 1 == fireBoyY)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX && bulletEnemy3Y[x] - 1 == fireBoyY + 1)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
            if (bulletEnemy3X[x] == fireBoyX && bulletEnemy3Y[x] - 1 == fireBoyY + 2)
            {
                fireBoyHealth = fireBoyHealth - 10;
                playerHealth();
            }
        }
    }
}

// Score
void addScore()
{
    score = score + 2;
}
void printScore()
{
    SetConsoleTextAttribute(hConsole, 9);
    gotoxy(110, 2);
    cout << "SCORE: " << score;
    SetConsoleTextAttribute(hConsole, 15);
}

// Enemies Functionality

// Enemy 1
void printEnemy1()
{
    SetConsoleTextAttribute(hConsole, 5);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int col = 0; col < 6; col++)
        {
            cout << icy[row][col];
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void eraseEnemy1()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy1X, enemy1Y + row);
        for (int col = 0; col < 6; col++)
        {
            cout << " ";
        }
    }
}
void moveEnemy1()
{
    char next1 = getCharAtxy(enemy1X + 2, enemy1Y);
    char next2 = getCharAtxy(enemy1X - 1, enemy1Y + 1);
    char next3 = getCharAtxy(enemy1X + 2, enemy1Y + 2);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        if (enemyDirection1 == "left")
        {
            char next = getCharAtxy(enemy1X + 3, enemy1Y + 3);
            if (next == '%')
            {
                eraseEnemy1();
                enemy1X = enemy1X - 1;
                printEnemy1();
            }
            if (next == '|')
            {
                enemyDirection1 = "right";
            }
        }
        if (enemyDirection1 == "right")
        {
            char next = getCharAtxy(enemy1X + 5, enemy1Y + 3);
            if (next == '%')
            {
                eraseEnemy1();
                enemy1X = enemy1X + 1;
                printEnemy1();
            }
            if (next == '|')
            {
                enemyDirection1 = "left";
            }
        }
    }
}
void enemy1_health()
{
    SetConsoleTextAttribute(hConsole, 5);
    char bar1 = 176;
    char bar2 = 219;
    gotoxy(110, 8);
    cout << "ENEMY 1 (ICY) HEALTH: ";
    gotoxy(135, 8);
    for (int i = 0; i < 20; i++)
    {
        cout << bar1;
    }
    cout << "\r";
    if (enemy1Health == 200)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 20; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 190)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 19; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 180)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 18; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 170)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 17; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 160)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 16; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 150)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 15; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 140)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 14; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 130)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 13; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 120)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 12; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 110)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 11; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 100)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 10; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 90)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 9; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 80)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 8; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 70)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 7; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 60)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 6; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 50)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 5; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 40)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 4; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 30)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 3; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 20)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 2; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 10)
    {
        gotoxy(135, 8);
        for (int i = 0; i < 1; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy1Health == 0)
    {
        removeEnemy1();
        fallKey();
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void removeEnemy1()
{
    eraseEnemy1();
    enemy1Present = false;
    keyX = enemy1X;
    keyY = enemy1Y;
    enemy1X = 0;
    enemy1Y = 45;
    stopEnemy2 = false;
    isEnemy2Free = true;
}
// Enemy 2
void printEnemy2()
{
    SetConsoleTextAttribute(hConsole, 2);
    for (int row = 0; row < 5; row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << watery[row][col];
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void eraseEnemy2()
{
    for (int row = 0; row < 5; row++)
    {
        gotoxy(enemy2X, enemy2Y + row);
        for (int col = 0; col < 3; col++)
        {
            cout << " ";
        }
    }
}
void moveEnemy2()
{
    if (enemy2Speed % 2 == 0)
    {
        if (enemyDirection2 == "down")
        {
            char next = getCharAtxy(enemy2X + 2, enemy2Y + 5);
            if (next == ' ')
            {
                eraseEnemy2();
                enemy2Y = enemy2Y + 1;
                printEnemy2();
            }
            if (next == '#')
            {
                enemyDirection2 = "up";
            }
        }
        if (enemyDirection2 == "up")
        {
            char next = getCharAtxy(enemy2X + 2, enemy2Y - 1);
            if (next == ' ')
            {
                eraseEnemy2();
                enemy2Y = enemy2Y - 1;
                printEnemy2();
            }
            if (next == '#')
            {
                enemyDirection2 = "down";
            }
        }
    }
    enemy2Speed++;
}
void enemy2_health()
{
    SetConsoleTextAttribute(hConsole, 2);
    char bar1 = 176;
    char bar2 = 219;
    gotoxy(110, 10);
    cout << "ENEMY 2 (WATERY) HEALTH: ";
    gotoxy(135, 10);
    for (int i = 0; i < 20; i++)
    {
        cout << bar1;
    }
    cout << "\r";
    if (enemy2Health == 200)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 20; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 190)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 19; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 180)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 18; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 170)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 17; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 160)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 16; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 150)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 15; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 140)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 14; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 130)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 13; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 120)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 12; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 110)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 11; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 100)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 10; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 90)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 9; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 80)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 8; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 70)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 7; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 60)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 6; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 50)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 5; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 40)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 4; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 30)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 3; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 20)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 2; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 10)
    {
        gotoxy(135, 10);
        for (int i = 0; i < 1; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy2Health == 0)
    {
        removeEnemy2();
        fallKey();
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void removeEnemy2()
{
    eraseEnemy2();
    enemy2Present = false;
    keyX = enemy2X;
    keyY = enemy2Y;
    enemy2X = 0;
    enemy2Y = 65;
    // stopEnemy3 = false;
}
void freeEnemy2()
{
    char maze[44][104] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', 21, ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '!', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', '|', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '|', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '$', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '#', '%', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '%', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', ' ', '@', ' ', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|'},
                          {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

    for (int row = 0; row < 44; row++)
    {
        gotoxy(85, 0 + row);
        for (int col = 0; col < 104; col++)
        {
            if (maze[row][col] == '$')
            {
                maze[row][col] = ' ';
                cout << maze[row][col];
            }
        }
        cout << endl;
    }
}

// Enemy 3
void printEnemy3()
{
    SetConsoleTextAttribute(hConsole, 8);
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for (int col = 0; col < 5; col++)
        {
            cout << airy[row][col];
        }
    }
    SetConsoleTextAttribute(hConsole, 15);
}
void eraseEnemy3()
{
    for (int row = 0; row < 3; row++)
    {
        gotoxy(enemy3X, enemy3Y + row);
        for (int col = 0; col < 5; col++)
        {
            cout << " ";
        }
    }
}
void moveEnemy3()
{
    if (moveRandom % 55 == 0)
    {
        eraseEnemy3();
        enemy3X = fireBoyX + 30;
        enemy3Y = fireBoyY;
        gotoxy(enemy3X, enemy3Y);
        printEnemy3();
    }
    moveRandom++;
}
void enemy3_health()
{
    char bar1 = 176;
    char bar2 = 219;
    gotoxy(110, 12);
    cout << "ENEMY 3 (AIRY) HEALTH: ";
    gotoxy(135, 12);
    for (int i = 0; i < 20; i++)
    {
        cout << bar1;
    }
    cout << "\r";
    if (enemy3Health == 200)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 20; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 190)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 19; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 180)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 18; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 170)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 17; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 160)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 16; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 150)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 15; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 140)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 14; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 130)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 13; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 120)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 12; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 110)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 11; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 100)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 10; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 90)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 9; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 80)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 8; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 70)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 7; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 60)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 6; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 50)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 5; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 40)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 4; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 30)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 3; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 20)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 2; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 10)
    {
        gotoxy(135, 12);
        for (int i = 0; i < 1; i++)
        {
            cout << bar2;
        }
    }
    else if (enemy3Health == 0)
    {
        removeEnemy3();
        fallKey();
    }
}
void removeEnemy3()
{
    eraseEnemy3();
    enemy3Present = false;
    keyX = enemy3X;
    keyY = enemy3Y;
    enemy3X = 0;
    enemy3Y = 85;
}
// void freeEnemy3();
void enemy3Left()
{
    char next = getCharAtxy(enemy3X - 1, enemy3Y + 1);
    if (next == ' ')
    {
        eraseEnemy3();
        enemy3X = enemy3X - 1;
        printEnemy3();
    }
}
void enemy3Right()
{
    char next = getCharAtxy(enemy3X + 5, enemy3Y + 2);
    if (next == ' ')
    {
        eraseEnemy3();
        enemy3X = enemy3X + 1;
        printEnemy3();
    }
}
void enemy3Up()
{
    char next = getCharAtxy(enemy3X + 2, enemy3Y - 1);
    if (next == ' ')
    {
        eraseEnemy3();
        enemy3Y = enemy3Y - 1;
        printEnemy3();
    }
}
void enemy3Down()
{
    char next = getCharAtxy(enemy3X + 2, enemy3Y + 3);
    if (next == ' ')
    {
        eraseEnemy3();
        enemy3Y = enemy3Y + 1;
        printEnemy3();
    }
}

// Door Functionality
void openDoor(char maze[][104])
{
    if (keyCount == 3)
    {
        for (int row = 0; row < 44; row++)
        {
            gotoxy(9, 0 + row);
            for (int col = 0; col < 104; col++)
            {
                if (maze[row][col] == '!')
                {
                    maze[row][col] = ' ';
                    cout << maze[row][col];
                }
            }
            cout << endl;
        }
        keyCount = 0;
        isDoorOpen = false;
    }
}

// Finish Game
bool winner()
{
    if (diamondCollect == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}