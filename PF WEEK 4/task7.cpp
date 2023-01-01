#include <iostream>
using namespace std;

void printName(string name);
main(){
	string userName;
	while(true){
		cout <<"Enter your Name: ";
		cin >> userName;
		printName(userName);
	}
}
void printName(string name){
	cout << "Your name is: " << name << endl;

}