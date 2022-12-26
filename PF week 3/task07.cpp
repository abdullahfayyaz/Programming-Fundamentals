#include <iostream>
using namespace std;
main(){
  int inputMb;
  int megabytes = 1024;
  int kilobytes = 1024;
  int bytes = 8;
  int bits;
  cout << "Enter Megabytes: ";
  cin >> inputMb;
  bits = inputMb * megabytes * kilobytes * bytes;
  cout << "In bits: " << bits;
} 
