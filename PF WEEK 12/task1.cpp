#include <fstream>
using namespace std;
main()
{
    fstream file;
    file.open("text.txt", ios ::out);
    file << "this is sample text";
    file.close();
}